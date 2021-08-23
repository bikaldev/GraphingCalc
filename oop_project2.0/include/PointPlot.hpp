#pragma once
#include "LinReg.hpp"
#include "Matrix.hpp"
#include "PointMarker.hpp"
#include <vector>

class PointPlot
{
private:
	std::vector<double> X, Y;
	sf::Vector2f origin, offset;
	float size;
	float amplitude;
	bool isInputOn;
	bool isFitOn;
	bool isDrawOn;
	LinReg LinearReg;

public:
	PointPlot()
	{
		this->origin = { 0.0f, 0.0f };
		this->offset = { 0.0f, 0.0f };
		this->isInputOn = false;
		this->isFitOn = false;
		this->isDrawOn = false;
	};

	PointPlot(sf::Vector2f org, sf::Vector2f off, float s)
	{
		origin = org;
		offset = off;
		size = s;
		this->isInputOn = false;
		this->isFitOn = false;
		this->isDrawOn = false;
	}

	void setOffset(sf::Vector2f);
	void setOrigin(sf::Vector2f);
	void setSize(float);
	void setAmplitude(float);
	void listenToStaticEvent(sf::RenderWindow& window);
	void markPoints(sf::RenderWindow& window);
	void fitPoints();
	void takeInput(sf::Event& evnt, sf::RenderWindow& window);
	~PointPlot()
	{}
};
