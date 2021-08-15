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

void PointPlot::setOrigin(sf::Vector2f org)
{
	this->origin = org;
	this->LinearReg.setOrigin(org);
}

void PointPlot::setOffset(sf::Vector2f off)
{
	this->offset = off;
}

void PointPlot::setSize(float s)
{
	this->size = s;
	this->LinearReg.setSize(s);
}

void PointPlot::setAmplitude(float amp)
{
	this->amplitude = amp;
}

void PointPlot::listenToStaticEvent(sf::RenderWindow& window)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		this->isFitOn = !this->isFitOn;
		this->isDrawOn = !this->isDrawOn;
	}
	if (this->isFitOn)
	{
		fitPoints();
		this->isFitOn = false;
	}
	if (this->isDrawOn)
	{
		this->LinearReg.drawFittedCurve(window);
	}
}

void PointPlot::takeInput(sf::Event& evnt, sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		this->isInputOn = !this->isInputOn;
	}
	if (this->isInputOn)
	{
		double x, y;
		static sf::Vector2i init_pos;
		sf::Vector2i final_pos;
		static bool isInput = false;
		if (evnt.type == evnt.MouseButtonPressed)
		{
			init_pos = sf::Mouse::getPosition(window);
		}
		if (evnt.type == evnt.MouseMoved)
		{
			isInput = false;
		}
		if (evnt.type == evnt.MouseButtonReleased)
		{
			final_pos = sf::Mouse::getPosition(window);
			if (init_pos.x - final_pos.x == 0 && init_pos.y - final_pos.y == 0)
			{
				isInput = true;
			}
		}
		if (isInput)
		{
			x = sf::Mouse::getPosition(window).x;
			y = sf::Mouse::getPosition(window).y;
			if (x >= offset.x && x <= offset.x + size && y >= offset.y && y <= offset.y + size)
			{
				X.push_back((x - origin.x) / this->amplitude);
				Y.push_back((y - origin.y) / this->amplitude);
			}
		}
	}
}

void PointPlot::markPoints(sf::RenderWindow& window)
{
	int size = static_cast<int>(this->X.size());
	for (int i = 0; i < size; i++)
	{
		PointMarker(this->X.at(i) * this->amplitude + this->origin.x, this->Y.at(i) * this->amplitude + this->origin.y).drawPoint(window);
	}
}

void PointPlot::fitPoints()
{
	int length = static_cast<int>(this->X.size());
	if (length <= 0)
	{
		return;
	}
	Custom::Matrix X_mat(length, 1);
	Custom::Matrix y_mat(length, 1);
	X_mat(this->X);
	y_mat(this->Y);
	LinReg L(X_mat, y_mat, origin, offset, size, amplitude);
	L.TrainModel(2);
	this->LinearReg = L;
}
