#include "hero.h"

Hero::Hero(const std::string &filename, sf::Vector2f position, float mass):position{position}, mass{mass}{
	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setOrigin(sf::Vector2f{static_cast<float>(texture.getSize().x), static_cast<float>(texture.getSize().y)});
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