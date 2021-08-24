#include "include/LinReg.hpp"

void LinReg::setOrigin(sf::Vector2f org)
{
	this->origin = org;
}

void LinReg::setSize(float s)
{
	CurveDrawer::X_range = s;
}

void LinReg::setAmplitude(float amp)
{
	CurveDrawer::amplitude = amp;
}

Matrix LinReg::addFeaturesandBias(Matrix X_design)
{
	// Custom::Matrix X_poly(X_design.row(), this->deg + 1);

	// try
	// {
	Matrix X_poly(X_design.row(), this->deg + 1);
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
	// }
	// catch (OUTOFRANGE e)
	// {
	// 	std::cerr << e.message() << std::endl;
	// }
	return X_poly;
}

void LinReg::TrainModel(int d, Fit::FitType tag)
{
	try
	{
		this->deg = d;
		this->special_tag = tag;
		this->X = this->addFeaturesandBias(this->X);
		this->Theta = Matrix::inv(Matrix::trans(X) * X) * Matrix::trans(X) * y; //Normal Equation
	}
	catch (SINGULAREXCEPTION e)
	{
		std::cerr << e.message() << std::endl;
	}
	catch (ORDEREXCEPTION e)
	{
		std::cout << e.message() << std::endl;
	}
}

double LinReg::hypothesis(double x)
{
	Matrix x_val(1, 1);
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
		b = convertor::Convert(Points(i, -hypothesis(i)), DefaultWindow);
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