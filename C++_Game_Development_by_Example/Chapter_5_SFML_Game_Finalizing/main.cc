#include <SFML/Graphics.hpp>

#include <vector>
#include <algorithm>

#include "base.h"
#include "hero.h"
#include "enemy.h"
#include "rocket.h"

struct GameData{
	int score = 0;
	float curTime = 0, prevTime = 0;
	std::vector<Rocket*> rockets;
	std::vector<Enemy*> enemies;
	std::chrono::time_point<std::chrono::steady_clock> rocketLastFired = std::chrono::steady_clock::now();
	bool isGameOver = false;
};

void shootRocket(std::vector<Rocket*>& rockets, const Hero& hero){
	auto* rocket = new Rocket{"res/rocket.png", hero.getSprite().getPosition(), 400};
	rockets.push_back(rocket);
}

bool checkCollision(const sf::Sprite& s1, const sf::Sprite& s2){
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}

void resetGame(GameData& gameData){
	gameData.score = 0, gameData.curTime = 0, gameData.prevTime = 0, gameData.rocketLastFired = std::chrono::steady_clock::now();
	std::for_each(gameData.rockets.begin(), gameData.rockets.end(), [](Rocket* i){delete i;});
	std::for_each(gameData.enemies.begin(), gameData.enemies.end(), [](Enemy* i){delete i;});
	gameData.rockets.clear(), gameData.enemies.clear();
}

void processInput(sf::RenderWindow& window, GameData& gameData,Hero& hero){
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
				if(gameData.isGameOver){
					gameData.isGameOver = false;
					resetGame(gameData);
				}
				else if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now()-gameData.rocketLastFired).count()>500){
					gameData.rocketLastFired=std::chrono::steady_clock::now();
					shootRocket(gameData.rockets, hero);
				}
			}
		}
	}
}

void update(float delta, Hero& hero, const sf::Vector2f& viewSize, GameData& gameData){
	hero.update(delta, viewSize);
	gameData.curTime+=delta;
	if(gameData.curTime>=(gameData.prevTime+1.125)){
		gameData.prevTime=gameData.curTime;
		auto* newEnemy = new Enemy{"res/enemy.png", viewSize};
		gameData.enemies.push_back(newEnemy);
	}
	if(!gameData.enemies.empty()){
		std::for_each(gameData.enemies.begin(), gameData.enemies.end(), [&delta](Enemy* i){i->update(delta);});
		gameData.enemies.erase(std::remove_if(gameData.enemies.begin(), gameData.enemies.end(), [&gameData](Enemy* i){
			if(i->getSprite().getPosition().x<0){
				delete i;
				gameData.isGameOver = true;
				return true;
			}
			else{
				return false;
			}
		}), gameData.enemies.end());
	}
	if(!gameData.rockets.empty()){
		std::for_each(gameData.rockets.begin(), gameData.rockets.end(), [&delta](Rocket* i){i->update(delta);});
		gameData.rockets.erase(std::remove_if(gameData.rockets.begin(), gameData.rockets.end(), [&viewSize](Rocket* i){
			if(i->getSprite().getPosition().x>viewSize.x){
				delete i;
				return true;
			}
			else{
				return false;
			}
		}), gameData.rockets.end());
	}
	if(!gameData.enemies.empty()&&!gameData.rockets.empty()){
		std::vector<Enemy*> removedEnemies;
		std::vector<Rocket*> removedRockets;
		gameData.enemies.erase(std::remove_if(gameData.enemies.begin(), gameData.enemies.end(), [&gameData, &removedEnemies](Enemy* i){
			for(auto j:gameData.rockets){
				if(checkCollision(i->getSprite(), j->getSprite())){
					++gameData.score;
					removedEnemies.push_back(i);
					return true;
				}
			}
			return false;
		}), gameData.enemies.end());
		gameData.rockets.erase(std::remove_if(gameData.rockets.begin(), gameData.rockets.end(), [&removedEnemies, &removedRockets](Rocket* i){
			for(auto& j:removedEnemies){
				if(checkCollision(i->getSprite(), j->getSprite())){
					removedRockets.push_back(i);
					return true;
				}
			}
			return false;
		}), gameData.rockets.end());
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

	GameData gameData;
	BaseObject sky{"res/sky.png"}, setting{"res/bg.png"};
	BaseFont snackerComicFont{"res/SnackerComic.ttf"}, arialFont{"res/arial.ttf"};
	BaseText headingText{snackerComicFont.getFont(), "Tiny Bazooka", 84, sf::Color::Red, sf::Vector2f{static_cast<float>(viewSize.x*0.5), static_cast<float>(viewSize.y*0.1)}};
	BaseText scoreText{arialFont.getFont(), "Score: 0", 45, sf::Color::Red, sf::Vector2f{static_cast<float>(viewSize.x*0.5), static_cast<float>(viewSize.y*0.1)}};
	BaseText tutorialText{arialFont.getFont(), "Press 'S' to re/start the game and shoot rockets, Up arrow to jump, Escape to quit", 23, sf::Color::Red, sf::Vector2f{static_cast<float>(viewSize.x*0.5), static_cast<float>(viewSize.y*0.25)}};
	Hero hero{"res/heroAnim.png", sf::Vector2f{static_cast<float>(viewSize.x*0.25), static_cast<float>(viewSize.y*0.5)}, 200, 4, 1};

	while(window.isOpen()){
		window.clear();

		processInput(window, gameData, hero);

		sf::Time delta = clock.restart();
		if(!gameData.isGameOver){
			update(delta.asSeconds(), hero, viewSize, gameData);
		}

		sky.draw(window);
		setting.draw(window);
		hero.draw(window);

		if(gameData.isGameOver||gameData.curTime<5){
			headingText.draw(window);
			tutorialText.draw(window);
		}
		else{
			scoreText.setText("Score: "+std::to_string(gameData.score));
			scoreText.draw(window);
		}

		std::for_each(gameData.enemies.begin(), gameData.enemies.end(), [&window](Enemy* i){i->draw(window);});
		std::for_each(gameData.rockets.begin(), gameData.rockets.end(), [&window](Rocket* i){i->draw(window);});

		window.display();
	}
}
