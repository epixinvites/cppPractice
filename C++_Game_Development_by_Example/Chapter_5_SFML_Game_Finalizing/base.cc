#include "base.h"
#include <stdexcept>

BaseObject::BaseObject(const std::string& filename, const sf::Vector2f& position):position{position}{
	if(!texture.loadFromFile(filename)){
		throw std::runtime_error{"Error loading texture"};
	}
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setOrigin(sf::Vector2f{static_cast<float>(texture.getSize().x/2), static_cast<float>(texture.getSize().y/2)});
}

BaseObject::BaseObject(const std::string& filename){
	if(!texture.loadFromFile(filename)){
		throw std::runtime_error{"Error loading texture"};
	}
	sprite.setTexture(texture);
}

void BaseObject::draw(sf::RenderWindow& window){
	window.draw(sprite);
}

sf::Vector2f& BaseObject::getPosition(){
	return position;
}

sf::Texture& BaseObject::getTexture(){
	return texture;
}

sf::Sprite& BaseObject::getSprite(){
	return sprite;
}

const sf::Vector2f& BaseObject::getPosition() const{
	return position;
}

const sf::Texture& BaseObject::getTexture() const{
	return texture;
}

const sf::Sprite& BaseObject::getSprite() const{
	return sprite;
}

BaseFont::BaseFont(const std::string& filename){
	if(!font.loadFromFile(filename)){
		throw std::runtime_error{"Error loading font"};
	}
}

sf::Font& BaseFont::getFont(){
	return font;
}

const sf::Font& BaseFont::getFont() const{
	return font;
};

BaseText::BaseText(sf::Font& font, const sf::String& textText, unsigned int textSize, const sf::Color& textColor, const sf::Vector2f& textPosition){
	text.setFont(font);
	text.setString(textText);
	text.setCharacterSize(textSize);
	text.setFillColor(textColor);
	text.setOrigin(sf::Vector2f{text.getLocalBounds().width/2, text.getLocalBounds().height/2});
	text.setPosition(textPosition);
}

void BaseText::draw(sf::RenderWindow& window){
	window.draw(text);
}

void BaseText::setText(const sf::String& alteredText){
	text.setString(alteredText);
}

sf::Text& BaseText::getText(){
	return text;
}

const sf::Text& BaseText::getText() const{
	return text;
}