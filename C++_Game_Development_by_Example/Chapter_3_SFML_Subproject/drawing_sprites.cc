#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

struct RenderObject{
	sf::Texture texture;
	sf::Sprite sprite;
};

void init_sprite(RenderObject object, const std::string &filename){
	object.texture.loadFromFile(filename);
	object.sprite.setTexture(object.texture);
}

void draw_sprite(sf::RenderWindow &window, sf::Sprite &Sprite){
	window.draw(Sprite);
}

int main(){
	sf::Vector2f viewSize{1024, 576};
	sf::VideoMode vm{static_cast<unsigned int>(viewSize.x), static_cast<unsigned int>(viewSize.y)};
	sf::RenderWindow window{vm, "Test window", sf::Style::Default};

	RenderObject sky, setting;

	init_sprite(sky.texture, sky.sprite, "res/sky.png");
	init_sprite(setting.texture, setting.sprite, "res/bg.png");

	while(window.isOpen()){
		window.clear();
		draw_sprite(window, skySprite);
		draw_sprite(window, settingSprite);
		window.display();
	}
}