#include "Grapher.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Graph Layout", sf::Style::Default);
	Grapher graph(600.0f, sf::Vector2f(0.0f, 0.0f));
	graph.addCurve("x = sin(y)");
	graph.addCurve("y = sin(x)");
	graph.addCurve("y = x + 10");
	graph.addCurve("y = x * sin(x)");
	while (window.isOpen())
	{
		window.clear();
		graph.drawLayout(window, true);
		graph.draw(window);
		graph.listenToStaticEvents(window);
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			graph.listenToLazyEvent(evnt, window);
			switch (evnt.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}

		window.display();
	}
	return 0;
}
