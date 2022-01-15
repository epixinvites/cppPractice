#include <SFML/Graphics.hpp>

#include <vector>
#include <algorithm>

#include "base.h"
#include "hero.h"
#include "enemy.h"
#include "rocket.h"

void shootRocket(std::vector<Rocket*>& rockets, const Hero& hero){
	auto* rocket = new Rocket{"res/rocket.png", hero.getSprite().getPosition(), 400};
	rockets.push_back(rocket);
}

bool checkCollision(const sf::Sprite& s1, const sf::Sprite& s2){
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

void processInput(sf::RenderWindow& window, std::vector<Rocket*>& rockets, std::chrono::time_point<std::chrono::steady_clock>& rocketLastFired, Hero& hero){
	sf::Event event{};
	while(window.pollEvent(event)){
		if(event.key.code==sf::Keyboard::Escape||event.type==sf::Event::Closed){
			window.close();
			return;
		}
		if(event.type==sf::Event::KeyPressed){
			if(event.key.code==sf::Keyboard::Up){
				hero.jump(750);
			}
			else if(event.key.code==sf::Keyboard::S){
				if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-rocketLastFired).count()>1250){
					rocketLastFired=std::chrono::steady_clock::now();
					shootRocket(rockets, hero);
				}
			}
		}
	}
}

void update(float delta, Hero& hero, const sf::Vector2f& viewSize, std::vector<Enemy*>& enemies, std::vector<Rocket*>& rockets, float& curTime, float& prevTime){
	hero.update(delta, viewSize);
	curTime+=delta;
	if(curTime>=(prevTime+1.125)){
		prevTime=curTime;
		auto* newEnemy = new Enemy{"res/enemy.png", viewSize};
		enemies.push_back(newEnemy);
	}
	if(!enemies.empty()){
		std::for_each(enemies.begin(), enemies.end(), [&delta](Enemy* i){i->update(delta);});
		enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](Enemy* i){
			if(i->getSprite().getPosition().x<0){
				delete i;
				return true;
			}
			else{
				return false;
			}
		}), enemies.end());
	}
	if(!rockets.empty()){
		std::for_each(rockets.begin(), rockets.end(), [&delta](Rocket* i){i->update(delta);});
		rockets.erase(std::remove_if(rockets.begin(), rockets.end(), [&viewSize](Rocket* i){
			if(i->getSprite().getPosition().x>viewSize.x){
				delete i;
				return true;
			}
			else{
				return false;
			}
		}), rockets.end());
	}
	if(!enemies.empty()&&!rockets.empty()){
		std::vector<Enemy*> removedEnemies;
		std::vector<Rocket*> removedRockets;
		enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [&rockets, &removedEnemies](Enemy* i){
			for(auto j:rockets){
				if(checkCollision(i->getSprite(), j->getSprite())){
					removedEnemies.push_back(i);
					return true;
				}
			}
			return false;
		}), enemies.end());
		rockets.erase(std::remove_if(rockets.begin(), rockets.end(), [&removedEnemies, &removedRockets](Rocket* i){
			for(auto& j:removedEnemies){
				if(checkCollision(i->getSprite(), j->getSprite())){
					removedRockets.push_back(i);
					return true;
				}
			}
			return false;
		}), rockets.end());
		std::for_each(removedEnemies.begin(), removedEnemies.end(), [](Enemy* i){delete i;});
		std::for_each(removedRockets.begin(), removedRockets.end(), [](Rocket* i){delete i;});
	}
}

int main(){
	sf::Vector2f viewSize{1024, 576};
	sf::VideoMode vm{static_cast<unsigned int>(viewSize.x), static_cast<unsigned int>(viewSize.y)};
	sf::RenderWindow window{vm, "Test window", sf::Style::Default};
	sf::Clock clock;
	window.setFramerateLimit(60);

	float curTime = 0, prevTime = 0;

	BaseObject sky{"res/sky.png"}, setting{"res/bg.png"};
	Hero hero{"res/hero.png", sf::Vector2f{static_cast<float>(viewSize.x*0.25), static_cast<float>(viewSize.y*0.5)}, 200};
	std::vector<Enemy*> enemies;
	std::vector<Rocket*> rockets;
	std::chrono::time_point<std::chrono::steady_clock> rocketLastFired = std::chrono::steady_clock::now();

	while(window.isOpen()){
		processInput(window, rockets, rocketLastFired, hero);

		sf::Time delta = clock.restart();
		update(delta.asSeconds(), hero, viewSize, enemies, rockets, curTime, prevTime);

		window.clear();

		sky.draw(window);
		setting.draw(window);
		hero.draw(window);

		std::for_each(enemies.begin(), enemies.end(), [&window](Enemy* i){i->draw(window);});
		std::for_each(rockets.begin(), rockets.end(), [&window](Rocket* i){i->draw(window);});

		window.display();
	}
}
