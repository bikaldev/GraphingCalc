#include "Grapher.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Graph Layout", sf::Style::Default);
	Grapher graph(400.0f, sf::Vector2f(100.0f, 100.0f));

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
			static bool isMousePressed = false;
			static sf::Vector2i init_position;
			if (evnt.type == evnt.MouseButtonPressed)
			{
				init_position = sf::Mouse::getPosition();
				isMousePressed = true;
			}
			if (evnt.type == evnt.MouseMoved && isMousePressed)
			{
				sf::Vector2i final_position = sf::Mouse::getPosition();
				graph.update(static_cast<sf::Vector2f>(static_cast<sf::Vector2f>(final_position - init_position)));
			}
			if (evnt.type == evnt.MouseButtonReleased)
			{
				isMousePressed = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				graph.reset();
			}
		}
		window.clear(sf::Color(150, 150, 150));
		graph.drawLayout(window, true);
		window.display();
	}
	return 0;
}