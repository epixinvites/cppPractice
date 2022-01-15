#include <SFML/Graphics.hpp>

int main(){
	sf::Vector2f viewSize{1024, 576};
	sf::VideoMode vm{static_cast<unsigned int>(viewSize.x), static_cast<unsigned int>(viewSize.y)};
	sf::RenderWindow window{vm, "Test window", sf::Style::Default};

	sf::RectangleShape rect{sf::Vector2f{static_cast<float>(500), static_cast<float>(250)}};
	rect.setFillColor(sf::Color::Cyan);
	rect.setPosition({viewSize.x/2, viewSize.y/2});
	rect.setOrigin(sf::Vector2f{rect.getSize().x/2, rect.getSize().y/2});

	sf::CircleShape circle{100};
	circle.setFillColor(sf::Color::White);
	circle.setPosition({viewSize.x/2, viewSize.y/2});
	circle.setOrigin(sf::Vector2f{circle.getRadius(), circle.getRadius()});

	sf::ConvexShape triangle;
	triangle.setPointCount(3);
	triangle.setPoint(0, sf::Vector2f{-100, 0});
	triangle.setPoint(1, sf::Vector2f{0, -100});
	triangle.setPoint(2, sf::Vector2f{100, 0});
	triangle.setFillColor(sf::Color{128, 0, 128, 255});
	triangle.setPosition({viewSize.x/2, viewSize.y/2});

	while(window.isOpen()){
		window.clear(sf::Color::Black);
		window.draw(rect);
		window.draw(circle);
		window.draw(triangle);
		window.display();
	}

	return 0;
}