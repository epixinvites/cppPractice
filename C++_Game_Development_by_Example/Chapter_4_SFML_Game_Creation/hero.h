#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "base.h"

class Hero : public BaseObject{
	bool isMoving = false;
	int jumpCount = 0;
	float mass = 0;
	float velocity = 0;
	const float gravity = 9.8;
	bool isOnGround = false;
public:
	Hero(const std::string &filename, const sf::Vector2f& position, float mass);
	void update(float delta, const sf::Vector2f& viewSize);
	void jump(float _velocity);

	bool& getIsMoving();
	bool& getIsOnGround();
};
