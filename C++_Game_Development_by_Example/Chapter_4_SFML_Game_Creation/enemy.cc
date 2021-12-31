#include "enemy.h"

#include <random>

Enemy::Enemy(const std::string& filename, const sf::Vector2f& position, float speed):position{position}, speed{speed}{
	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setOrigin(sf::Vector2f{static_cast<float>(texture.getSize().x/2), static_cast<float>(texture.getSize().y/2)});
}

Enemy::Enemy(const std::string& filename, const sf::Vector2f& viewSize){
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> rng{400, 800};
	speed = rng(generator)*-1;
	float y_pos = rng(generator)/1000.0;
	int randomGenerated = rng(generator)%3;
	switch(randomGenerated){
		case 0:
			position = sf::Vector2f{viewSize.x, static_cast<float>(viewSize.y * y_pos)};
			break;
		case 1:
			position = sf::Vector2f{viewSize.x, static_cast<float>(viewSize.y * y_pos)};
			break;
		case 2:
			position = sf::Vector2f{viewSize.x, static_cast<float>(viewSize.y * y_pos)};
			break;
		default:
			break;
	}

	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	sprite.setOrigin(sf::Vector2f{static_cast<float>(texture.getSize().x/2), static_cast<float>(texture.getSize().y/2)});
}


void Enemy::update(float delta){
	sprite.move(sf::Vector2f{static_cast<float>(speed*delta), 0});
}

void Enemy::draw(sf::RenderWindow& window){
	window.draw(sprite);
}

sf::Vector2f& Enemy::getPosition(){
	return position;
}

sf::Texture& Enemy::getTexture(){
	return texture;
}

sf::Sprite& Enemy::getSprite(){
	return sprite;
}