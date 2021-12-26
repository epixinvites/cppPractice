#include <SFML/Graphics.hpp>

int main(){
	sf::Vector2f viewSize{600, 400};
	sf::VideoMode vm{static_cast<unsigned int>(viewSize.x), static_cast<unsigned int>(viewSize.y)};
	sf::RenderWindow window{vm, "Test window", sf::Style::Default};

	sf::RectangleShape rect{sf::Vector2f{static_cast<float>(300), static_cast<float>(150)}};
	rect.setFillColor(sf::Color::Cyan);
	rect.setPosition({viewSize.x/2, viewSize.y/2});
	rect.setOrigin(sf::Vector2f{rect.getSize().x/2, rect.getSize().y/2});

	while(window.isOpen()){
		window.clear(sf::Color::Black);
		window.draw(rect);
		window.display();
	}

	return 0;
}