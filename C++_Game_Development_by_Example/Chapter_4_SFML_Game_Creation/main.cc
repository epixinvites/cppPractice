#include <SFML/Graphics.hpp>
#include "hero.h"

class LoadedObject{
	sf::Texture texture;
	sf::Sprite sprite;
public:
	explicit LoadedObject(const std::string& filename){
		texture.loadFromFile(filename);
		sprite.setTexture(texture);
	}

	sf::Sprite& getSprite(){
		return sprite;
	}

	sf::Texture& getTexture(){
		return texture;
	}

	void draw(sf::RenderWindow& window){
		window.draw(sprite);
	}
};

void processInput(sf::RenderWindow& window){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.key.code==sf::Keyboard::Escape||event.type==sf::Event::Closed){
			window.close();
			return;
		}
	}
}

void update(float delta){

}

int main(){
	sf::Vector2f viewSize{1024, 576};
	sf::VideoMode vm{static_cast<unsigned int>(viewSize.x), static_cast<unsigned int>(viewSize.y)};
	sf::RenderWindow window{vm, "Test window", sf::Style::Default};
	sf::Clock clock;
	window.setFramerateLimit(60);

	LoadedObject sky{"res/sky.png"}, setting{"res/bg.png"};

	while(window.isOpen()){
		processInput(window);

		sf::Time delta = clock.restart();
		update(delta.asSeconds());

		window.clear();

		sky.draw(window);
		setting.draw(window);

		window.display();
	}
}