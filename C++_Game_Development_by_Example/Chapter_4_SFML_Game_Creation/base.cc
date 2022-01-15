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