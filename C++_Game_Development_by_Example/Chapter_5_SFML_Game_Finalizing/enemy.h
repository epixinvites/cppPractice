#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "base.h"

class Enemy : public BaseObject{
	float speed;
public:
	Enemy(const std::string& filename, const sf::Vector2f& position, float speed);
	Enemy(const std::string& filename, const sf::Vector2f& viewSize);
	void update(float delta);
};
