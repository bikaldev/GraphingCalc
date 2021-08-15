#pragma once
#include "CurveDrawer.hpp"
#include "Matrix.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string>

namespace Fit
{
enum FitType
{
	poly,
	exp,
	log
};
}

class LinReg : public CurveDrawer
{
private:
	Custom::Matrix X, y, Theta;
	int deg;
	Fit::FitType special_tag;

	Custom::Matrix addFeaturesandBias(Custom::Matrix);

public:
	LinReg() = default;
	LinReg(Custom::Matrix X_design, Custom::Matrix y_target, sf::Vector2f org, sf::Vector2f off, float size, float amplitude) :
		CurveDrawer(org, off, size, amplitude)
	{
		this->X = X_design;
		this->y = y_target;
	}

	void setOrigin(sf::Vector2f org);
	void setSize(float);
	void setAmplitude(float);
	void TrainModel(int, Fit::FitType);
	double hypothesis(double);
	void drawFittedCurve(sf::RenderWindow& window);
};

void LinReg::setOrigin(sf::Vector2f org)
{
	this->origin = org;
}

void LinReg::setSize(float s)
{
	CurveDrawer::X_range = s;
}

void LinReg::setAmplitude(float amp) {
	CurveDrawer::amplitude = amp;
}

Custom::Matrix LinReg::addFeaturesandBias(Custom::Matrix X_design)
{
	Custom::Matrix X_poly(X_design.row(), this->deg + 1);
	for (int i = 0; i < X_design.row(); i++)
	{
		for (int j = 0; j < this->deg + 1; j++)
		{
			switch (this->special_tag)
			{
				case Fit::poly:
					X_poly.setElement(i, j, pow(X_design(i, 0), j));
					break;
				case Fit::exp:
					if (j == 0)
						X_poly.setElement(i, j, 1);
					else
						X_poly.setElement(i, j, exp(pow(X_design(i, 0), j)));
					break;
				case Fit::log:
					if (j == 0)
						X_poly.setElement(i, j, 1);
					else
						X_poly.setElement(i, j, log(pow(X_design(i, 0), j)));
					break;
				default:
					break;
			}
		}
	}
	return X_poly;
}

void LinReg::TrainModel(int d, Fit::FitType tag = Fit::poly)
{
	this->deg = d;
	this->special_tag = tag;
	this->X = this->addFeaturesandBias(this->X);
	this->Theta = Custom::inv(Custom::trans(X) * X) * Custom::trans(X) * y; //Normal Equation
}

double LinReg::hypothesis(double x)
{
	Custom::Matrix x_val(1, 1);
	x_val({ x });
	x_val = this->addFeaturesandBias(x_val);
	return (x_val * this->Theta)(0, 0);
}

void LinReg::drawFittedCurve(sf::RenderWindow& window)
{
	std::vector<Points> c;
	WindowSize DefaultWindow;
	DefaultWindow.ActualRange = Points((offset.x - origin.x) / amplitude, (offset.x + X_range - origin.x) / amplitude);
	DefaultWindow.MagnifiedRange = Points(offset.x - origin.x, offset.x + X_range - origin.x);
	DefaultWindow.plane.width = X_range;
	DefaultWindow.plane.height = X_range;
	DefaultWindow.plane.top = origin.y;
	DefaultWindow.plane.left = origin.x;

	//convert to screen points
	Points b;
	for (double i = DefaultWindow.ActualRange._x; i <= DefaultWindow.ActualRange._y; i += 0.01)
	{
		//std::cout<<"\n\n\n\n\n\n\nnope, I am the one being used\n\n\n\n\n\n\n\n\n\n";
		b = convertor::Convert(Points(i, hypothesis(i)), DefaultWindow);
		c.push_back(b);
	}

	//Draw Curve
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