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
