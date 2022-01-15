#include "hero.h"

Hero::Hero(const std::string &filename, const sf::Vector2f& position, float mass):BaseObject{filename, position}, mass{mass}{}

void Hero::update(float delta, const sf::Vector2f& viewSize){
	velocity -= mass*gravity*delta;
	position.y -= velocity*delta;
	sprite.setPosition(position);
	if(position.y>=viewSize.y*0.75){
		position.y=viewSize.y*0.75;
		velocity=0;
		isOnGround=true;
		jumpCount=0;
	}
}

void Hero::jump(float _velocity){
	if(jumpCount<=2){
		jumpCount++;
		velocity=_velocity;
		isOnGround=false;
	}
}

bool& Hero::getIsMoving(){
	return isMoving;
}

bool& Hero::getIsOnGround(){
	return isOnGround;
}
