#include "etp.hpp"
#include "windowsize.hpp"

std::vector<Points> convertor::Plotytox(std::string s, WindowSize& p)
{
	//this should solve the problem for the y and x dependent variables
	std::vector<Points> c;
	Points b;

	Parser parse(s);
	for (double i = p.ActualRange._x; i <= p.ActualRange._y; i += 0.025)
	{
		b = convertor::Convert(Points(i, -parse.EvaluatePostfix(i)), p);
		c.push_back(b);
	}
	return c;
}

std::vector<Points> convertor::Plotxtoy(std::string s, WindowSize& p)
{
	std::vector<Points> c;

	Points b;

	Parser parse(s);
	for (double i = p.ActualRange._x; i <= p.ActualRange._y; i += 0.025)
	{
		b = convertor::Convert(Points(parse.EvaluatePostfix(0, i), -i), p);
		c.push_back(b);
	}
	return c;
}

Points convertor::Convert(Points b, WindowSize& k)
{
	Points a;
	a._x = k.plane.left + k.MagnifiedRange._x + k.plane.width * (b._x - k.ActualRange._x) / (k.ActualRange._y - k.ActualRange._x);
	a._y = k.plane.top + k.MagnifiedRange._x + k.plane.width * (b._y - k.ActualRange._x) / (k.ActualRange._y - k.ActualRange._x);

	return a;
}
//is there any use of this function
Points convertor::implicitConvert(Points a)
{

	a._x *= 100;
	a._y *= 100;
	a._x += 500;
	a._y += 400;
	return a;
}