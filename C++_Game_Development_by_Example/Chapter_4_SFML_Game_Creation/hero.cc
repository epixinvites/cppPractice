#include "hero.h"

Hero::Hero(const std::string &filename, const sf::Vector2f& position, float mass):position{position}, mass{mass}{
	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setOrigin(sf::Vector2f{static_cast<float>(texture.getSize().x/2), static_cast<float>(texture.getSize().y/2)});
}

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


sf::Vector2f& Hero::getPosition(){
	return position;
}

bool& Hero::getIsMoving(){
	return isMoving;
}

bool& Hero::getIsOnGround(){
	return isOnGround;
}

sf::Sprite& Hero::getSprite(){
	return sprite;
}

sf::Texture& Hero::getTexture(){
	return texture;
}

void Hero::draw(sf::RenderWindow &window){
	window.draw(sprite);
}
