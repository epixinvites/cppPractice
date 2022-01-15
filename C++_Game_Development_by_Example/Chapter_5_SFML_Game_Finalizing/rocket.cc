#include "rocket.h"

Rocket::Rocket(const std::string& filename, const sf::Vector2f& _position, float _speed):BaseObject{filename, _position}, speed{_speed}{}

void Rocket::update(float delta){
	sprite.move(sf::Vector2f{speed*delta, 0});
}
