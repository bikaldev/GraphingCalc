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
	sf::Vector2f startpos, endpos, controlpos;
	float i = offset.x - origin.x;
	while (i <= offset.x + X_range - origin.x)
	{
		//For Sine and Cosine Curves
		// startpos.x = i;
		// startpos.y = amplitude * -sin((2 * PI) * i / period);

		// controlpos.x = startpos.x + period / (2 * scale);
		// controlpos.y = amplitude * -sin((2 * PI) * (i + period / (2 * scale)) / period);

		// endpos.x = startpos.x + period / scale;
		// endpos.y = amplitude * -sin((2 * PI * (i + period / scale)) / period);

		startpos.x = i;
		startpos.y = amplitude * hypothesis(i);

		controlpos.x = startpos.x + period / (2 * scale);
		controlpos.y = amplitude * hypothesis(i + period / (2 * scale));

		endpos.x = startpos.x + period / scale;
		endpos.y = amplitude * hypothesis(i + period / scale);

		startpos = startpos + origin;
		controlpos = controlpos + origin;
		endpos = endpos + origin;

		// if (endpos.y < offset.y + X_range && endpos.y > offset.y)
		// {
		beziersQuad(startpos, endpos, controlpos, 3.0f, window);
		// }
		i += period / scale;
	}
}