#pragma once

#include <string>
#include <SFML/Graphics.hpp>

class BaseObject{
protected:
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Texture texture;
public:
	explicit BaseObject(const std::string& filename, const sf::Vector2f& position);
	explicit BaseObject(const std::string& filename);

	void draw(sf::RenderWindow& window);

	sf::Texture& getTexture();
	sf::Sprite& getSprite();
	sf::Vector2f& getPosition();

	const sf::Texture& getTexture() const;
	const sf::Sprite& getSprite() const;
	const sf::Vector2f& getPosition() const;
};

class BaseFont{
protected:
	sf::Font font;
public:
	explicit BaseFont(const std::string& filename);

	sf::Font& getFont();
	const sf::Font& getFont() const;
};

class BaseText{
protected:
	sf::Text text;
public:
	explicit BaseText(sf::Font& font, const sf::String& textText, unsigned int textSize, const sf::Color& textColor, const sf::Vector2f& textPosition);

	void draw(sf::RenderWindow& window);
	void setText(const sf::String& alteredText);

	sf::Text& getText();
	const sf::Text& getText() const;
};
