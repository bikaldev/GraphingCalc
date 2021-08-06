#pragma once
//using pragma once here stopped the redifination of class error
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "cartesian.hpp"

using namespace std;

class sfLine : public sf::Drawable
{
public:
	sfLine()
	{}
	sfLine(const Cartesian& point1, const Cartesian& point2, const float& t) :
		color(sf::Color::Red),
		thickness(t),
		vertices(sf::TriangleStrip, 4)
	{
		sf::Vector2f delta { (point2._x - point1._x), (point2._y - point1._y) };
		float length = sqrtf(delta.x * delta.x + delta.y * delta.y);
		float scale = thickness / (2 * length);
		sf::Vector2f radius = { -scale * delta.y, scale * delta.x };
		vertices[0].position = { point1._x - radius.x, point1._y - radius.y };
		vertices[1].position = { point1._x + radius.x, point1._y + radius.y };
		vertices[2].position = { point2._x - radius.x, point2._y - radius.y };
		vertices[3].position = { point2._x + radius.x, point2._y + radius.y };

		for (int i = 0; i < 4; ++i)
			vertices[i].color = color;
	}
	~sfLine()
	{}

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(vertices, states);
	}

private:
	//sf::VertexArray vertices;
	sf::Color color;
	float thickness;
	sf::VertexArray vertices;
	///sf::Color color;
};
/*
class beziersQuad : public sfLine
{
private:
	sf::Vector2f startPos;
	sf::Vector2f endPos;
	sf::Vector2f controlPos;
	float tn;

public:
	beziersQuad(const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c, const float& d, sf::RenderWindow& thatwindow) :
		startPos { a },
		endPos { b },
		controlPos { c },
		tn { d }
	{
		const float step = 1.f / 25;
		sf::Vector2f previous = startPos;
		sf::Vector2f current = { 0.f, 0.f };
		float t = 0.f;
		for (int i = 0; i <= 25; i++)
		{
			t = step * i;
			float a = pow(1 - t, 2);
			float b = 2 * (1 - t) * t;
			float c = pow(t, 2);
			//the easing functions aren,t suitable here because they don't take a control point
			current.y = a * startPos.y + b * controlPos.y + c * endPos.y;
			current.x = a * startPos.x + b * controlPos.x + c * endPos.x;

			sfLine lineq(previous, current, tn);
			thatwindow.draw(lineq);
			//thatwindow.display();
			previous = current;
		}
	}

	~beziersQuad()
	{}
};
*/