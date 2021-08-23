#include "PointPlot.hpp"

PointPlot::PointPlot()
{
	this->origin = { 0.0f, 0.0f };
	this->offset = { 0.0f, 0.0f };
	this->isInputOn = false;
	this->isFitOn = false;
	this->isDrawOn = false;
	this->degree = 1;
}

PointPlot::PointPlot(sf::Vector2f org, sf::Vector2f off, float s)
{
	origin = org;
	offset = off;
	size = s;
	this->isInputOn = false;
	this->isFitOn = false;
	this->isDrawOn = false;
	this->degree = 1;
}

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
	this->LinearReg.setAmplitude(amp);
}

void PointPlot::setDegree(int deg)
{
	if (deg < 1 || deg > 10)
		return;
	this->degree = deg;
}

void PointPlot::listenToStaticEvent(sf::RenderWindow& window)
{

	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	// {
	// 	this->isFitOn = !this->isFitOn;
	// 	this->isDrawOn = !this->isDrawOn;
	// }
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

void PointPlot::takePoint(double x, double y)
{
	this->X.push_back(x);
	this->Y.push_back(y);
}

void PointPlot::fitCurve()
{
	this->isFitOn = true;
	this->isDrawOn = true;
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
		PointMarker(this->X.at(i) * this->amplitude + this->origin.x,
			-this->Y.at(i) * this->amplitude + this->origin.y)
			.drawPoint(window);
	}
}

void PointPlot::fitPoints()
{
	int length = static_cast<int>(this->X.size());
	if (length <= 0)
	{
		return;
	}
	Matrix X_mat(length, 1);
	Matrix y_mat(length, 1);
	X_mat(this->X);
	y_mat(this->Y);
	LinReg L(X_mat, y_mat, origin, offset, size, amplitude);
	L.TrainModel(degree);
	this->LinearReg = L;
}