#include "Grapher.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Graph Layout", sf::Style::Default);
	Grapher graph(600.0f, sf::Vector2f(0.0f, 0.0f));
	while (window.isOpen())
	{
		window.clear(sf::Color(150, 150, 150));
		graph.drawLayout(window, true);
		graph.listenToStaticEvents(window);
		graph.drawCurve(quad, window);
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

double quad(double x)
{
	return x * sin(x);
}