#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Hero{
	sf::Vector2f position;

	sf::Texture texture;
	sf::Sprite sprite;

	bool isMoving = false;
	int jumpCount = 0;
	float mass = 0;
	float velocity = 0;
	const float gravity = 9.8;
	bool isOnGround = false;
public:
	Hero(const std::string &filename, sf::Vector2f position, float mass);
	void update(float delta, const sf::Vector2f& viewSize);
	void jump(float velocity);


	sf::Vector2f& getPosition();
	bool& getIsMoving();
	sf::Sprite& getSprite();
	sf::Texture& getTexture();
	void draw(sf::RenderWindow& window);
};

