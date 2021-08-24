#pragma once
#include "CurveDrawer.hpp"
#include "LinRegException.hpp"
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
	Matrix X, y, Theta;
	int deg;
	Fit::FitType special_tag;

	Matrix addFeaturesandBias(Matrix);

public:
	LinReg() = default;
	LinReg(Matrix X_design, Matrix y_target, sf::Vector2f org, sf::Vector2f off, float size, float amplitude) :
		CurveDrawer(org, off, size, amplitude)
	{
		this->X = X_design;
		this->y = y_target;
	}

	void setOrigin(sf::Vector2f org);
	void setSize(float);
	void setAmplitude(float);
	void TrainModel(int d, Fit::FitType tag = Fit::poly);
	double hypothesis(double);
	void drawFittedCurve(sf::RenderWindow& window);
};
