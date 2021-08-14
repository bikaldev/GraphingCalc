#include <SFML/Graphics.hpp>
#include <iostream>
#include "button.hpp"
#include "textbox.hpp"
#include "gui.hpp"
//even declaration of object must only be done after the pressing of button
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

	Button btn6;
	btn6.setLabel("Equations");
	btn6.Create();
	btn6.setPosition(25.f,0.f);
	Button btn7;
	btn7.setLabel("Points");
	btn7.Create();
	btn7.setPosition(btn6.width()+50.f, 0.f);
	Button btn8;
	btn8.setLabel("Equations");
	btn8.Create();
	btn8.setPosition(25.f, 700.f);
	Button btn9;
	btn9.setLabel("Points");
	btn9.Create();
	btn9.setPosition(btn8.width()+50.f, 700.f);


	std::vector<Button*> buttons;

	EqnPlot eq(350.f, 350.f, "eqnPlot", sf::Vector2f{100.f, 50.f}, sf::Vector2f{500.f, 500.f},"assets/arial.ttf");
	
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
	/*for(int i = 0; i<2;i++)
	{
		std::vector<Textbox> temp;
		pointbox.push_back(temp);
		for (int j = 0; j < 5; j++)
		{
			//make a formula for this part.
			pointbox[i].push_back(Textbox(sf::Vector2f{60,40},sf::Vector2f{50+(60+5)*j,500+(40+5)*i},"assets/arial.ttf", Type::IP));
			
		}
		
	}*/


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
		btn8.listen(window, event);
		btn9.listen(window, event);
		//btn8.listen_events(event);
		//btn9.listen_events(event);
		// Loop to handle event
		while (window.pollEvent(event)) 
		{
			tb1.listenForText(event);
			tb2.listenForText(event);
			tb3.listenForText(event);
			tb4.listenForText(event);
			eq.listenForText(event);
			/*
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					pointbox[i][j].listenForText(event);
				}
				
			}*/
			if (event.type == sf::Event::Closed) { // When close button is pressed
				window.close();
			}
			tb1.listenForClick(window);
			tb2.listenForClick(window);
			tb3.listenForClick(window);
			tb4.listenForClick(window);
			eq.listenForClick(window);
			/*for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					pointbox[i][j].listenForClick(window);
				}
				
			}*/
			//this is a must do part as well
			/*
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) { // When mouse button 1 is pressed
				// Handle elements
				if (btn1.isPressed() == true) {}
				if (btn2.isPressed() == true) {}
				if (btn3.isPressed() == true) {}
				if (btn4.isPressed() == true) {}
				if (btn5.isPressed() == true) {}
				if (btn6.isPressed() == true) {}
				if (btn7.isPressed() == true) {}
				if (btn8.isPressed() == true) {}
				if (btn9.isPressed() == true) {}
				if (eq.isPressed() == true) {}
				
			}*/
			/*
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
						x[j]=pointbox[0][j].getString();
					}
					for (int j = 0; j < 5; j++)
					{
						y[j]=pointbox[1][j].getString();
					}

					for (int k = 0; k <5 ; k++)
					{
						std::cout<<x[k]<<"\t"<<y[k]<<std::endl;
					}
				}	
				if (btn6.isPressed(2) == true) {
					
				}
				if (btn7.isPressed(2) == true) {

					
				}
				if (eq.isPressed(2) == true) {
					std::cout<<"get string"<<eq.getString()<<std::endl;

					
				}


				

				
				
			}*/
			//i do not know the need of this part
			/*
			if (event.type == sf::Event::MouseMoved) { // When mouse is moved
				// Handle elements
				if (btn1.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn2.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn3.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn4.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn5.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn6.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn7.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn8.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (btn9.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
				if (eq.withinBounds(event.mouseMove.x, event.mouseMove.y) == true) {}
			}*/
			
		}
		/*
		if (btn6.isPressed(2) == true) {
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
			
		}
		if (btn7.isPressed(2) == true) {

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					window.draw(pointbox[i][j]);
				}
				
			}
			window.draw(btn5.Sprite);
			window.draw(btn5.Label);
		}
		if (btn8.isPressed(2) == true) {
			for (int i = 0; i < 3; i++)
			{
				buttons.push_back(new Button(200.f*i, 200.f*i, "Added"));
				window.draw(buttons[i]->Sprite);
				window.draw(buttons[i]->Label);
			}
			
			
		}
		if (btn9.isPressed(2) == true) {
			//how to aviod seg fault in this part of the code.
			//i believe the best method here is to do something like set visible.
			//delete buttons[0];
			int i = 0; 	
			while (!buttons.empty())
			{
				i++;
				//error due to double free ie delete button is being used multiple times
				delete buttons[i];
				std::cout<<i<<std::endl;
				buttons.pop_back();
				window.clear();
			}
			
			
		}
		*/

		// Draw everything
		/*
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
		*/
		
		//we need a double loop to draw
		/*
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				window.draw(*pointbox[i][j]);
			}
			
		}
		*/

		
		window.draw(btn6.Sprite);
		window.draw(btn6.Label);
		window.draw(btn7.Sprite);
		window.draw(btn7.Label);
		window.draw(btn8.Sprite);
		window.draw(btn8.Label);
		//this method should also work.
		//btn8.draw(window);
		window.draw(btn9.Sprite);
		window.draw(btn9.Label);
		
		window.draw(eq.Sprite);
		window.draw(eq.Label);
		window.draw(eq);
		//window.draw(*pointbox[0][0]);

		

		if (btn8.isEqn == true)
		{
			window.draw(tb1);
			window.draw(btn1.Sprite);
			window.draw(btn1.Label);

		}

		
		if (btn9.isPoints == true)
		{
			window.clear();	
			//main stuff to draw still needs to be drawn even after clear.
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					std::cout<<"not my fault"<<std::endl;
					window.draw(*pointbox[i][j]);
		
				}
				
			}
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					pointbox[i][j]->listenForClick(window);
				}
				
			}

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					pointbox[i][j]->listenForText(event);
				}
				
			}
			
		}

		

		window.display();


		
		

		
	}

	return 0;
}


