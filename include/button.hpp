#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
	sf::Texture Idle;
	sf::Texture Hover;
	sf::Texture Click;
	sf::Font Font;
	float x = 0;
	float y = 0;
	float x2 = 0;
	float y2 = 0;
	int fineAdjust = 0;
    bool once;
public:
    Button(){}
    Button(float a, float b, std::string c)
	{
		setPosition(a, b);
		Create();
		setLabel(c);
		
	}
	sf::Sprite Sprite;
	sf::Text Label;
	bool hovered;
	//bool press = false;
	bool clicked;
	std::string label = "Button";
	std::string clickLabel = label;
	std::string hoverLabel = label;
	void Create() {
		Idle.loadFromFile("assets/btn_idle.png");
		//Idle.setScale(sf::Vector2f(0.5f, 2.f));
		Hover.loadFromFile("assets/btn_hover.png");
		Click.loadFromFile("assets/btn_click.png");
		Font.loadFromFile("assets/arial.ttf");
		Label.setFont(Font);
		Label.setCharacterSize(24);
		Label.setFillColor(sf::Color::Red);
		setLabel(label);
		Sprite.setTexture(Idle);
		//i belive this is for alignment
		if (Label.getLocalBounds().height <= 18) { fineAdjust = 0; }
		if (Label.getLocalBounds().height >= 23) { fineAdjust = 5; }
		Label.setOrigin(sf::Vector2f(((Sprite.getLocalBounds().width - Label.getLocalBounds().width) / 2) * (-1), ((Sprite.getLocalBounds().height - (Label.getLocalBounds().height - fineAdjust) * 1.7) / 2) * (-1)));
	}
	void setState(std::string type) {
		if (type == "Idle") {
			Sprite.setTexture(Idle);
		}
		else if (type == "Hover") {
			Sprite.setTexture(Hover);
		}
		else if (type == "Click") {
			Sprite.setTexture(Click);
		}
	}
	void setPosition(float newX, float newY) {
		x = newX;
		y = newY;
		x2 = newX + Sprite.getLocalBounds().width;
		y2 = newY + Sprite.getLocalBounds().height;
		Sprite.setPosition(sf::Vector2f(newX, newY));
		Label.setPosition(sf::Vector2f(newX, newY));
	}
	//this seems to be here to change the level. Not sure if this is necessary
	void setLabel(std::string x) {
		std::string oldLabel = label;
		std::string oldClickLabel = clickLabel;
		if (x != clickLabel && x != hoverLabel) {
			label = x;
		}
		if (clickLabel == oldLabel && x != hoverLabel) {
			clickLabel = x;
		}
		if (hoverLabel == oldLabel && x != oldClickLabel) {
			hoverLabel = x;
		}
		Label.setString(x);
		if (Label.getLocalBounds().height <= 18) { fineAdjust = 0; }
		if (Label.getLocalBounds().height >= 23) { fineAdjust = 5; }
		Label.setOrigin(sf::Vector2f(((Sprite.getLocalBounds().width - Label.getLocalBounds().width) / 2) * (-1), ((Sprite.getLocalBounds().height - (Label.getLocalBounds().height - fineAdjust) * 1.7) / 2) * (-1)));
	}
	int height() { return Sprite.getLocalBounds().height; }
	int width() { return Sprite.getLocalBounds().width; }

	void draw(sf::RenderWindow window) {
		window.draw(Sprite);
		window.draw(Label);
    }

    void listen(sf::RenderWindow &window) 
	{
		sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
		if (mouse_position.x >= x &&
			mouse_position.x <= (x2) &&
			mouse_position.y >= y &&
			mouse_position.y <= (y2)) {
			hovered = true;
			Sprite.setTexture(Hover);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				if (!once) {
					clicked = true;
					
					once = true;
					Sprite.setTexture(Hover);
				} else {
					clicked = false;
					Sprite.setTexture(Click);
					//Sprite.setTexture(Hover);
				}
			} else {
				clicked = false;
				once = false;
				Sprite.setTexture(Hover);

			}
		} 
		else {
			clicked = false;
			hovered = false;
			Sprite.setTexture(Idle);

		}
	}
};
