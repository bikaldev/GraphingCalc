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

public:
	CurveDrawer() = default;
	CurveDrawer(sf::Vector2f org, sf::Vector2f off, int x_range = 700, int amp = 1)
	{
		this->origin = org;
		this->offset = off;
		X_range = x_range;
		amplitude = amp;
	}

	void draw(std::string s, sf::RenderWindow& window);
	//void drawFromModel(LinReg& L, sf::RenderWindow& widow);
};

void CurveDrawer::draw(std::string s, sf::RenderWindow& window)
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
		sfLine line(p1, p2, 3.f, sf::Color::Blue);
		window.draw(line);
	}
}

// void CurveDrawer::draw(double (*f)(double), sf::RenderWindow& window)
// {
// 	// double y = f(10) * 0;
// 	sf::Vector2f startpos, endpos, controlpos;
// 	float i = offset.x - origin.x;
// 	while (i <= offset.x + X_range - origin.x)
// 	{
// 		// //For Sine and Cosine Curves
// 		// startpos.x = i + y;
// 		// startpos.y = amplitude * -sin((2 * PI) * i / period);

// 		// controlpos.x = startpos.x + period / (2 * scale);
// 		// controlpos.y = amplitude * -sin((2 * PI) * (i + period / (2 * scale)) / period);

// 		// endpos.x = startpos.x + period / scale;
// 		// endpos.y = amplitude * -sin((2 * PI * (i + period / scale)) / period);

// 		//For other curves
// 		startpos.x = i;
// 		startpos.y = amplitude * -f(i);
// 		controlpos.x = startpos.x + period / (2 * scale);
// 		controlpos.y = amplitude * -f(i + period / (2 * scale));
// 		endpos.x = startpos.x + period / scale;
// 		endpos.y = amplitude * -f(i + period / scale);

// 		//Translate to the x-axis line
// 		// startpos = startpos + sf::Vector2f(offset.x, origin.y);
// 		// controlpos = controlpos + sf::Vector2f(offset.x, origin.y);
// 		// endpos = endpos + sf::Vector2f(offset.x, origin.y);
// 		startpos = startpos + origin;
// 		controlpos = controlpos + origin;
// 		endpos = endpos + origin;

// 		// if (endpos.y < offset.y + X_range && endpos.y > offset.y)
// 		// {
// 		beziersQuad(startpos, endpos, controlpos, 3.0f, window);
// 		//Draw the curve
// 		// }

// 		//DrawLineBezier(startpos,endpos,3.0,BLACK);
// 		//Next iteration of curve
// 		i += period / scale;
// 	}
// }

// void CurveDrawer::drawFromModel(LinReg& L, sf::RenderWindow& window)
// {
// 	sf::Vector2f startpos, endpos, controlpos;
// 	float i = offset.x - origin.x;
// 	while (i <= offset.x + X_range - origin.x - 0.4 * X_range)
// 	{
// 		startpos.x = i;
// 		startpos.y = amplitude * -L.hypothesis(i);
// 		controlpos.x = startpos.x + period / (2 * scale);
// 		controlpos.y = amplitude * -L.hypothesis(i + period / (2 * scale));
// 		endpos.x = startpos.x + period / scale;
// 		endpos.y = amplitude * -L.hypothesis(i + period / scale);

// 		startpos = startpos + origin;
// 		controlpos = controlpos + origin;
// 		endpos = endpos + origin;

// 		if (endpos.y < offset.y + X_range && endpos.y > offset.y)
// 		{
// 			beziersQuad(startpos, endpos, controlpos, 3.0f, window);
// 		}
// 		i += period / scale;
// 	}
//}
