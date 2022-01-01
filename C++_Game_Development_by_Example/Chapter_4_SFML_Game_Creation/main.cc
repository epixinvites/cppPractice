#include <SFML/Graphics.hpp>

#include <vector>
#include <algorithm>

#include "base.h"
#include "hero.h"
#include "enemy.h"
#include "rocket.h"

void processInput(sf::RenderWindow& window, Hero& hero){
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
		}
	}
}

void update(float delta, Hero& hero, const sf::Vector2f& viewSize, std::vector<Enemy*>& enemies, float& curTime, float& prevTime){
	hero.update(delta, viewSize);
	curTime+=delta;
	if(curTime>=(prevTime+1.125)){
		prevTime=curTime;
		auto* newEnemy = new Enemy{"res/enemy.png", viewSize};
		enemies.push_back(newEnemy);
	}
	if(!enemies.empty()){
		for(auto& i:enemies){
			i->update(delta);
		}
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

	while(window.isOpen()){
		processInput(window, hero);

		sf::Time delta = clock.restart();
		update(delta.asSeconds(), hero, viewSize, enemies, curTime, prevTime);

		window.clear();

		sky.draw(window);
		setting.draw(window);
		hero.draw(window);

		std::for_each(enemies.begin(), enemies.end(), [&window](Enemy* i){i->draw(window);});

		window.display();
	}
}
