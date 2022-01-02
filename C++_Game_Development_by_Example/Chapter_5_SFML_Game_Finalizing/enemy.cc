#include "enemy.h"

#include <random>

Enemy::Enemy(const std::string& filename, const sf::Vector2f& position, float speed):BaseObject{filename, position}, speed{speed}{}

sf::Vector2f genSpawnPosition(const sf::Vector2f& viewSize){
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> rng{400, 800};
	float y_pos = rng(generator)/1000.0;
	int randomGenerated = rng(generator)%3;
	sf::Vector2f position;
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
	return position;
}

Enemy::Enemy(const std::string& filename, const sf::Vector2f& viewSize):BaseObject{filename, genSpawnPosition(viewSize)}{
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution<int> rng{400, 800};
	speed = rng(generator)*-1;
}


void Enemy::update(float delta){
	sprite.move(sf::Vector2f{static_cast<float>(speed*delta), 0});
}