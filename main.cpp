//now this code needs to be integrated to the main program files.
#include "gui.hpp"
#include <iostream>

int main() {
    Gui g;
    g.main();
}
// #include "LinReg.hpp"
// #include <SFML/Graphics.hpp>
// #include <iostream>

// int main()
// {
// 	Matrix x(8, 1), y(8, 1);
// 	x({ 1, 2, 3, 4, 5, 6, 7, 8 });
// 	y({ 1, 100, 300, 456, 789, 987, 1234, 1546 });
// 	LinReg model(x, y, sf ::Vector2f(100, 100), sf::Vector2f(0, 0), 1280, 10);
// 	model.TrainModel(7);
// 	sf::RenderWindow window(sf::VideoMode(1280.0f, 720.0f), "Graph Layout", sf::Style::Default);
// 	while (window.isOpen())
// 	{

// 		window.clear();

// 		sf::Event evnt;
// 		while (window.pollEvent(evnt))
// 		{

// 			switch (evnt.type)
// 			{
// 				case sf::Event::Closed:
// 					window.close();
// 					break;
// 				default:
// 					break;
// 			}
// 			model.drawFittedCurve(window);
// 			window.display();
// 		}
// 	}
// 	return 0;
// }