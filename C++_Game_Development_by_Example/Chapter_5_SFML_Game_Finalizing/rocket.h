#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "base.h"

class Rocket : public BaseObject{
	float speed = 0;
public:
	Rocket(const std::string& filename, const sf::Vector2f& position, float _speed);
	void update(float delta);
};