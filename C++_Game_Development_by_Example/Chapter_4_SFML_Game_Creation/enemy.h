#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Enemy{
	sf::Vector2f position;

	sf::Texture texture;
	sf::Sprite sprite;

	float speed;
public:
	Enemy(const std::string& filename, const sf::Vector2f& position, float speed);
	Enemy(const std::string& filename, const sf::Vector2f& viewSize);
	void update(float delta);
	void draw(sf::RenderWindow& window);

	sf::Vector2f& getPosition();
	sf::Texture& getTexture();
	sf::Sprite& getSprite();
};
