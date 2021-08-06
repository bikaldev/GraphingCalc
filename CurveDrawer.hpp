#pragma once
#include "BezierQuad.hpp"
#include "shuntingyard.hpp"
#include "cartesian.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>
#include <vector>
#define PI 3.1415

class CurveDrawer
{
protected:
	//this is the obtianed expression from text field
	string s;
	int X_range;
	//The period of the sin and cosine fuction
	int period;
	//The amplitude of the sine or cosine function
	int amplitude;
	//The factor to show how small our elemental line should be. The more the value the smoother the graph will get.
	int scale_factor;
	float scale;
	sf::Vector2f origin, offset;

public:
	CurveDrawer() = default;
	CurveDrawer(sf::Vector2f org, sf::Vector2f off, int x_range = 700, int amp = 1, int per = 200, int scale_fac = 4)
	{
		this->origin = org;
		this->offset = off;
		X_range = x_range;
		period = per * amp;
		amplitude = amp;
		scale_factor = scale_fac;
		scale = pow(2, scale_factor);
	}

	void draw(double (*f)(double), sf::RenderWindow& window);
	
	//void drawFromModel(LinReg& L, sf::RenderWindow& widow);
};


void CurveDrawer::draw(double (*f)(double), sf::RenderWindow& window)
{
	// double y = f(10) * 0;
	sf::Vector2f startpos, endpos, controlpos;
	float i = offset.x - origin.x;
	vector<Cartesian> c;
    queue<Token*> infix = StringToInfix(s);
    queue<Token*> postfix = InfixToPostfix(infix);
	//vector<Cartesian> CurveDrawer::ConvertExpression(s);
	//add the equations here
	while (i <= offset.x + X_range - origin.x)
	{
		c.push_back(Cartesian(EvaluatePostfix(postfix,i),i));

		// //For Sine and Cosine Curves
		// startpos.x = i + y;
		// startpos.y = amplitude * -sin((2 * PI) * i / period);

		// controlpos.x = startpos.x + period / (2 * scale);
		// controlpos.y = amplitude * -sin((2 * PI) * (i + period / (2 * scale)) / period);

		// endpos.x = startpos.x + period / scale;
		// endpos.y = amplitude * -sin((2 * PI * (i + period / scale)) / period);

		//For other curves
		//startpos.x = i;
		//startpos.y = amplitude * -f(i);
		//controlpos.x = startpos.x + period / (2 * scale);
		//controlpos.y = amplitude * -f(i + period / (2 * scale));
		//endpos.x = startpos.x + period / scale;
		//endpos.y = amplitude * -f(i + period / scale);

		//Translate to the x-axis line
		// startpos = startpos + sf::Vector2f(offset.x, origin.y);
		// controlpos = controlpos + sf::Vector2f(offset.x, origin.y);
		// endpos = endpos + sf::Vector2f(offset.x, origin.y);
		//startpos = startpos + origin;
		//controlpos = controlpos + origin;
		//endpos = endpos + origin;

		// if (endpos.y < offset.y + X_range && endpos.y > offset.y)
		// {
		//beziersQuad(startpos, endpos, controlpos, 3.0f, window);
		//Draw the curve
		// }

		//DrawLineBezier(startpos,endpos,3.0,BLACK);
		//Next iteration of curve
		//i += period / scale;
	}
	Cartesian a,b;
	for (size_t i = 0; i < c.size(); i++)
	{
		a=c[i];
		b=c[i+1];
		sfLine line(a,b,3.f);
		window.draw(line);
	}
	
}

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
