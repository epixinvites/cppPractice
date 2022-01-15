#include <SFML/Graphics.hpp>
#include <string>

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

void processInput(sf::RenderWindow& window, bool &isPlayerMoving){
	sf::Event event;
	while(window.pollEvent(event)){
		if(event.key.code==sf::Keyboard::Escape||event.type==sf::Event::Closed){
			window.close();
			return;
		}
		if(event.type==sf::Event::KeyPressed){
			if(event.key.code==sf::Keyboard::Right){
				isPlayerMoving = true;
			}
		}
		else if(event.type==sf::Event::KeyReleased){
			if(event.key.code==sf::Keyboard::Right){
				isPlayerMoving = false;
			}
		}
	}
}

void moveCharacter(float delta, bool isPlayerMoving, sf::Sprite& sprite){
	if(isPlayerMoving){
		sprite.move(sf::Vector2f{static_cast<float>(50)*delta, 0});
	}
}

int main(){
	sf::Vector2f viewSize{1024, 576};
	sf::VideoMode vm{static_cast<unsigned int>(viewSize.x), static_cast<unsigned int>(viewSize.y)};
	sf::RenderWindow window{vm, "Test window", sf::Style::Default};
	sf::Clock clock;

	LoadedObject sky{"res/sky.png"}, setting{"res/bg.png"}, character{"res/hero.png"};
	character.getSprite().setPosition(sf::Vector2f{viewSize.x/2, viewSize.y/2});
	character.getSprite().setOrigin(sf::Vector2f{static_cast<float>(character.getTexture().getSize().x/2.0), static_cast<float>(character.getTexture().getSize().y/2.0)});

	bool isPlayerMoving = false;

	while(window.isOpen()){
		processInput(window, isPlayerMoving);

		sf::Time delta = clock.restart();
		moveCharacter(delta.asSeconds(), isPlayerMoving, character.getSprite());

		window.clear();
		sky.draw(window);
		setting.draw(window);
		character.draw(window);

		window.display();
	}
}