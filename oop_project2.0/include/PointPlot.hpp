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
	float degree;
	bool isInputOn;
	bool isFitOn;
	bool isDrawOn;
	LinReg LinearReg;

public:
	//constructors:
	PointPlot();
	PointPlot(sf::Vector2f org, sf::Vector2f off, float s);
	//functions
	void fitCurve();
	void setOffset(sf::Vector2f);
	void setOrigin(sf::Vector2f);
	void setSize(float);
	void setAmplitude(float);
	void setDegree(int deg);
	void listenToStaticEvent(sf::RenderWindow& window);
	void markPoints(sf::RenderWindow& window);
	void fitPoints();
	void takeInput(sf::Event& evnt, sf::RenderWindow& window);
	void takePoint(double x, double y);
	void clear();
	//destructor
	~PointPlot()
	{}
};