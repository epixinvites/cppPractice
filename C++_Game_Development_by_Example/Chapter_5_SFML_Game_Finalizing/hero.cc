#include "hero.h"

Hero::Hero(const std::string &filename, const sf::Vector2f& position, float mass, int frameCount, float animationDuration):BaseObject{filename, position}, mass{mass}, frameCount{frameCount}, animationDuration{animationDuration}, spriteSize{sf::Vector2i{92, 126}}{
	sprite.setTextureRect(sf::IntRect{0, 0, spriteSize.x, spriteSize.y});
	sprite.setOrigin(sf::Vector2f{static_cast<float>(spriteSize.x/2), static_cast<float>(spriteSize.y/2)});
}

void Hero::update(float delta, const sf::Vector2f& viewSize){
	elapsedTime += delta;
	int animationFrame = static_cast<int>((elapsedTime/animationDuration)*frameCount)%frameCount;
	sprite.setTextureRect(sf::IntRect{animationFrame*spriteSize.x, 0, spriteSize.x, spriteSize.y});

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
