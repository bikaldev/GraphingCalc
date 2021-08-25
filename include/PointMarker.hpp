#pragma once
#include <SFML/Graphics.hpp>
#define POINT_RADIUS 4.0f
#define TAG_HEIGHT 10.0f
#define TAG_WIDTH 20.0f
#define TAG_DISPLACEMENT 5.0f

class PointMarker
{
private:
	double x, y;
	sf::Color fillColor;

public:
	PointMarker() = default;
	PointMarker(double x, double y)
	{
		this->x = x;
		this->y = y;
		this->fillColor = sf::Color::Black;
	}

	PointMarker(sf::Vector2f point)
	{
		this->x = point.x;
		this->y = point.y;
		this->fillColor = sf::Color::Black;
	}

	void setFillColor(sf::Color);
	void drawPoint(sf::RenderWindow& window);
	void listenToEvent(sf::Event evnt, sf::RenderWindow& window);

	//private:
	//void showPointTag(sf::RenderWindow& window);
};