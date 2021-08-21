#include "CurveDrawer.hpp"

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