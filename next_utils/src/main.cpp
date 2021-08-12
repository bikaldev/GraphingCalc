#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.hpp"
#include "textbox.hpp"

//using namespace std;

void stringEvaluator(std::string &k);

int main()
{

	sf::RenderWindow window;
	window.create(sf::VideoMode(1920, 1080), "Test", sf::Style::Titlebar | sf::Style::Close); // Unresizable window with titlebar
	//window.setFramerateLimit(60);
	/// window.setVerticalSyncEnabled(true); // Switch animation might not work if this is used

	// Create elements
	//window.clear(sf::Color::Black);
	//the first is size and second is position

	float tb_h=50.f;
	float tb_w=300.f;
	float s_x=50.f;
	float s_y=50.f;
	Textbox tb1(sf::Vector2f{tb_w, tb_h}, sf::Vector2f{s_x, s_y},"assets/arial.ttf");
	Button btn1;
	btn1.setLabel("Plot"); // Has to run before button is creaated
	btn1.Create();
	btn1.setPosition(s_x+tb_w+25.f , s_y);

	Textbox tb2(sf::Vector2f{tb_w, tb_h}, sf::Vector2f{s_x, s_y+tb_h+40.f},"assets/arial.ttf");
	Button btn2;
	btn2.setLabel("Plot"); // Has to run before button is creaated
	btn2.Create();
	btn2.setPosition(s_x+tb_w+25.f , s_y+tb_h+40.f);

	Textbox tb3(sf::Vector2f{tb_w, tb_h}, sf::Vector2f{s_x, s_y+tb_h*2+40.f*2},"assets/arial.ttf");
	Button btn3;
	btn3.setLabel("Plot"); // Has to run before button is creaated
	btn3.Create();
	btn3.setPosition( s_x+tb_w+25.f, s_y+tb_h*2+40.f*2);

	Textbox tb4(sf::Vector2f{tb_w, tb_h}, sf::Vector2f{s_x, s_y+tb_h*3+40.f*3},"assets/arial.ttf");
	Button btn4;
	btn4.setLabel("Plot"); // Has to run before button is creaated
	btn4.Create();
	btn4.setPosition(s_x+tb_w+25.f, s_y+tb_h*3+40.f*3);

	Button btn5;
	btn5.setLabel("Plot"); // Has to run before button is creaated
	btn5.Create();
	btn5.setPosition(s_x+tb_w-150.f, s_y+tb_h*4+40.f*4);


	//an table like field for drawing points
	//better to make this longer and not higher.
	//Textbox obj[2][5];
	//lets make a buttons for points so that only it can be displayed
	std::vector<std::vector<Textbox*>> pointbox;
	for(int i = 0; i<2;i++)
	{
		std::vector<Textbox*> temp;
		pointbox.push_back(temp);
		for (int j = 0; j < 5; j++)
		{
			//make a formula for this part.
			pointbox[i].push_back(new Textbox(sf::Vector2f{60,40},sf::Vector2f{50+(60+5)*j,500+(40+5)*i},"assets/arial.ttf", Type::IP));
			
		}
		
	}


	//Button btn2;
	//btn2.setLabel("Add"); // Has to run before button is creaated
	//btn2.Create();
	//btn2.setPosition(300.f + 10, 100.f);
	/// btn1.setPosition(20.f, 780.f - btn1.height()); // Bottom left


	// Main loop
	while (window.isOpen())
	{
		// Take event
		sf::Event event;
		// Loop to handle event
		while (window.pollEvent(event)) 
		{
			tb1.listenForText(event);
			tb2.listenForText(event);
			tb3.listenForText(event);
			tb4.listenForText(event);

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					pointbox[i][j]->listenForText(event);
				}
				
			}
			if (event.type == sf::Event::Closed) { // When close button is pressed
				window.close();
			}
			tb1.listenForClick(window);
			tb2.listenForClick(window);
			tb3.listenForClick(window);
			tb4.listenForClick(window);
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					pointbox[i][j]->listenForClick(window);
				}
				
			}
			//this is a must do part as well
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { // When mouse button 1 is pressed
				// Handle elements
				if (btn1.isPressed() == true) {}
				if (btn2.isPressed() == true) {}
				if (btn3.isPressed() == true) {}
				if (btn4.isPressed() == true) {}
				if (btn5.isPressed() == true) {}
				
			}
	
			//this is a must do part
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) { // When mouse button 1 is released
				// Handle elements
				if (btn1.isPressed(2) == true) {
					std::cout << "Event: Mouse Button Released" << std::endl;
					std::cout<< "the string entered is: " << tb1.getString()<<std::endl;
					// Code executed when this button has been pressed
				}
				if (btn2.isPressed(2) == true) {
					std::cout << "Event: Mouse Button Released" << std::endl;
					std::cout<< "the string entered is: " << tb2.getString()<<std::endl;
					// Code executed when this button has been pressed
				}
				if (btn3.isPressed(2) == true) {
					std::cout << "Event: Mouse Button Released" << std::endl;
					std::cout<< "the string entered is: " << tb3.getString()<<std::endl;
					// Code executed when this button has been pressed
				}
				if (btn4.isPressed(2) == true) {
					std::cout << "Event: Mouse Button Released" << std::endl;
					std::cout<< "the string entered is: " << tb4.getString()<<std::endl;
					// Code executed when this button has been pressed
				}
				if (btn5.isPressed(2) == true) {
					//here data is to be initialized 
					std::string x[5];
					std::string y[5];
					for (int j = 0; j < 5; j++)
					{
						x[j]=pointbox[0][j]->getString();
					}
					for (int j = 0; j < 5; j++)
					{
						y[j]=pointbox[1][j]->getString();
					}

					for (int k = 0; k <5 ; k++)
					{
						std::cout<<x[k]<<"\t"<<y[k]<<std::endl;
					}
					
				
					
					// Code executed when this button has been pressed
				}
				
			}
			//i do not know the need of this part
			if (event.type == sf::Event::MouseMoved) { // When mouse is moved
				// Handle elements
				if (btn1.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn2.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn3.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn4.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn5.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
			}

		}

		// Draw everything
		window.clear(sf::Color::Black);
		window.draw(tb1);
		window.draw(btn1.Sprite);
		window.draw(btn1.Label);
		window.draw(tb2);
		window.draw(btn2.Sprite);
		window.draw(btn2.Label);
		window.draw(tb3);
		window.draw(btn3.Sprite);
		window.draw(btn3.Label);
		window.draw(tb4);
		window.draw(btn4.Sprite);
		window.draw(btn4.Label);
		window.draw(btn5.Sprite);
		window.draw(btn5.Label);
		
		//we need a double loop to draw
		
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				window.draw(*pointbox[i][j]);
			}
			
		}

		
		//window.draw(*pointbox[0][0]);

		window.display();
	}

	return 0;
}


