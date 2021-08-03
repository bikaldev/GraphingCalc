#pragma once
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

void PointMarker::setFillColor(sf::Color c)
{
	this->fillColor = c;
}

void PointMarker::drawPoint(sf::RenderWindow& window)
{
	sf::CircleShape point(POINT_RADIUS);
	point.setPosition(this->x, this->y);
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

// void PointMarker::showPointTag(sf::RenderWindow& window)
// {
// 	// sf::Text poitDim;
// 	// sf::RectangleShape tagBg(sf::Vector2f(TAG_HEIGHT, TAG_WIDTH));
// 	// tagBg.setPosition(this->x + TAG_DISPLACEMENT, this->y + TAG_DISPLACEMENT);
// 	//pointDim.setString(strcat("(",static_cast<string>this))
// }