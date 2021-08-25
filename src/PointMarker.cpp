#include "PointMarker.hpp"

void PointMarker::setFillColor(sf::Color c)
{
	this->fillColor = c;
}

void PointMarker::drawPoint(sf::RenderWindow& window)
{
	sf::CircleShape point(POINT_RADIUS);
	point.setPosition(this->x - POINT_RADIUS, this->y - POINT_RADIUS);
	point.setFillColor(this->fillColor);
	window.draw(point);
}

void PointMarker::listenToEvent(sf::Event evnt, sf::RenderWindow& window)
{
	sf::Vector2i clickPos;
	if (evnt.type == evnt.MouseButtonPressed)
	{
		clickPos = sf::Mouse::getPosition(window);
		if (clickPos.x >= this->x - POINT_RADIUS && clickPos.x <= this->x + POINT_RADIUS && clickPos.y >= this->y - POINT_RADIUS && clickPos.y <= this->y + POINT_RADIUS)
		{
			//showPointTag(window);
		}
	}
}