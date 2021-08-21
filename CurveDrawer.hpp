#pragma once
#include "BezierQuad.hpp"
#include "etp.hpp"
#include "points.hpp"
#include "windowsize.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

class CurveDrawer
{
protected:
	int X_range;
	//The amplitude of the sine or cosine function
	int amplitude;
	sf::Vector2f origin, offset;
	sf::Color color;

public:
	CurveDrawer() = default;
	CurveDrawer(sf::Vector2f org, sf::Vector2f off, int x_range = 700, int amp = 1, sf::Color col = sf::Color::Blue)
	{
		this->origin = org;
		this->offset = off;
		this->color = col;
		X_range = x_range;
		amplitude = amp;
	}

	void drawYDep(std::string s, sf::RenderWindow& window);
	void drawXDep(std::string s, sf::RenderWindow& window);
	void setColor(sf::Color);
	//void drawFromModel(LinReg& L, sf::RenderWindow& widow);
};