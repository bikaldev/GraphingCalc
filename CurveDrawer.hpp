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

void CurveDrawer::drawYDep(std::string s, sf::RenderWindow& window)
{
	std::vector<Points> c;
	WindowSize DefaultWindow;
	DefaultWindow.ActualRange = Points((offset.x - origin.x) / amplitude, (offset.x + X_range - origin.x) / amplitude);
	DefaultWindow.MagnifiedRange = Points(offset.x - origin.x, offset.x + X_range - origin.x);
	DefaultWindow.plane.width = X_range;
	DefaultWindow.plane.height = X_range;
	DefaultWindow.plane.top = origin.y;
	DefaultWindow.plane.left = origin.x;

	c = convertor::Plotytox(s, DefaultWindow);
	sf::Vector2f p1, p2;

	for (size_t i = 0; i < c.size() - 1; i++)
	{
		p1.x = c[i]._x;
		p1.y = c[i]._y;

		p2.x = c[i + 1]._x;
		p2.y = c[i + 1]._y;
		sfLine line(p1, p2, 3.f, color);
		window.draw(line);
	}
}

void CurveDrawer::drawXDep(std::string s, sf::RenderWindow& window)
{
	std::vector<Points> c;
	WindowSize DefaultWindow;
	DefaultWindow.ActualRange = Points((offset.y - origin.y) / amplitude, (offset.y + X_range - origin.y) / amplitude);
	DefaultWindow.MagnifiedRange = Points(offset.y - origin.y, offset.y + X_range - origin.y);
	DefaultWindow.plane.width = X_range;
	DefaultWindow.plane.height = X_range;
	DefaultWindow.plane.top = origin.y;
	DefaultWindow.plane.left = origin.x;

	c = convertor::Plotxtoy(s, DefaultWindow);
	sf::Vector2f p1, p2;

	for (size_t i = 0; i < c.size() - 1; i++)
	{
		p1.x = c[i]._x;
		p1.y = c[i]._y;

		p2.x = c[i + 1]._x;
		p2.y = c[i + 1]._y;
		sfLine line(p1, p2, 3.f, color);
		window.draw(line);
	}
}

void CurveDrawer::setColor(sf::Color col)
{
	this->color = col;
}