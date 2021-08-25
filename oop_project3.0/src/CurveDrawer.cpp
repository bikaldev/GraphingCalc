#include "CurveDrawer.hpp"
//for y=f(x) form
void CurveDrawer::drawYDep(std::string s, sf::RenderWindow& window)
{
	std::vector<Points> c;
	WindowSize DefaultWindow;
	DefaultWindow.ActualRange = Points((offset.x - origin.x) / amplitude, (offset.x + X_range - origin.x) / amplitude);
	DefaultWindow.MagnifiedRange = Points(offset.x - origin.x, offset.x + X_range - origin.x);
	DefaultWindow.plane.width = X_range;
	DefaultWindow.plane.height = X_range;
	DefaultWindow.plane.top = origin.y;
	DefaultWindow.plane.left = origin.x;
	//this might be a better place to keep the exception
	//this works properly
	try
	{
		c = convertor::Plotytox(s, DefaultWindow);
	}
	catch (INVALIDFORMAT e)
	{
		std::cerr << e.get_message() << '\n';
		throw;
	}

	sf::Vector2f p1, p2;
	//perhaps we need to change the code here to make sure that the tangent lines work
	for (size_t i = 0; i < c.size() - 1; i++)
	{
		//an exception occurs here is y=((x we should be completely omitting this part of the code;
		p1.x = c[i]._x;
		p1.y = c[i]._y;

		p2.x = c[i + 1]._x;
		p2.y = c[i + 1]._y;
		//we need to reduce this exact condition
		if ((p2.y > p1.y && p2.y - p1.y > 500.f) || (p2.y < p1.y && p1.y - p2.y > 500.f))
		{

			//dont draw in this condition
			//std::cout<<"this condition is stisfied"<<std::endl;
		}
		else
		{
			sfLine line(p1, p2, 3.f, color);
			window.draw(line);
		}

		///sfLine line(p1, p2, 3.f, color);
		//window.draw(line);
	}
}

void CurveDrawer::drawXDep(std::string s, sf::RenderWindow& window)
{
	std::vector<Points> c;
	WindowSize DefaultWindow;
	DefaultWindow.ActualRange = Points((offset.y - origin.y) / amplitude, (offset.y + X_range - origin.y) / amplitude);
	DefaultWindow.MagnifiedRange = Points(offset.y - origin.y, offset.y + X_range - origin.y);
	DefaultWindow.plane.width = X_range;
	DefaultWindow.plane.height = X_range;
	DefaultWindow.plane.top = origin.y;
	DefaultWindow.plane.left = origin.x;

	try
	{
		c = convertor::Plotxtoy(s, DefaultWindow);
	}
	catch (INVALIDFORMAT e)
	{
		std::cerr << e.get_message() << '\n';
		throw;
	}
	sf::Vector2f p1, p2;

	for (size_t i = 0; i < c.size() - 1; i++)
	{
		p1.x = c[i]._x;
		p1.y = c[i]._y;

		p2.x = c[i + 1]._x;
		p2.y = c[i + 1]._y;

		if ((p2.x > p1.x && p2.x - p1.x > 1.f) || (p2.x < p1.x && p1.x - p2.x > 1.f))
		{
			//std::cout<<"this condition is stisfied"<<std::endl;
		}
		else
		{
			sfLine line(p1, p2, 3.f, color);
			window.draw(line);
		}

		//sfLine line(p1, p2, 3.f, color);
		//window.draw(line);
	}
}

void CurveDrawer::setColor(sf::Color col)
{
	this->color = col;
}