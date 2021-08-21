#include "etp.hpp"
#include "windowsize.hpp"

std::vector<Points> convertor::Plotytox(std::string s, WindowSize& p)
{
	//std::cout<<"\n\n\n\n\n\n\nnope, I am the one being used\n\n\n\n\n\n\n\n\n\n";
	std::vector<Points> c;
	Points b;
	std::queue<Token*> infix = StringToInfix(s);
	std::queue<Token*> postfix = InfixToPostfix(infix);
	for (double i = p.ActualRange._x; i <= p.ActualRange._y; i += 0.1)
	{
		//std::cout<<"\n\n\n\n\n\n\nnope, I am the one being used\n\n\n\n\n\n\n\n\n\n";
		b = convertor::Convert(Points(i, -EvaluatePostfix(postfix, i)), p);
		c.push_back(b);
	}
	return c;
	//for (double i = -20; i <= 20; i+= 0.5)
	//  c.push_back(Points(i,EvaluatePostfix(postfix,i)));
	//return c;
}

std::vector<Points> convertor::Plotxtoy(std::string s, WindowSize& p)
{
	std::vector<Points> c;
	std::queue<Token*> infix = StringToInfix(s);
	std::queue<Token*> postfix = InfixToPostfix(infix);
	Points b;
	//why does this work?
	//perhaps we should use the safe area idea.
	for (double i = p.ActualRange._x; i <= p.ActualRange._y; i += 0.1)
	{
		//std::cout<<"\n\n\n\n\n\n\nI am the one being used\n\n\n\n\n\n\n\n\n\n";
		b = convertor::Convert(Points(EvaluatePostfix(postfix, 0,i), i), p);
		c.push_back(b);
	}
	return c;
}

Points convertor::Convert(Points b, WindowSize& k)
{
	//std::cout<<"before conversion"<<std::endl;
	//std::cout<<b._x<<"   and   "<<b._y<<std::endl;
	Points a;
	// a._x = k.plane.left + k.plane.width * (b._x - k.Min._x) / (k.Max._x - k.Min._x);
	// a._y = k.plane.top + k.plane.height * (k.Max._y - b._y) / (k.Max._y - k.Min._y);
	a._x = k.plane.left + k.MagnifiedRange._x + k.plane.width * (b._x - k.ActualRange._x) / (k.ActualRange._y - k.ActualRange._x);
	a._y = k.plane.top + k.MagnifiedRange._x + k.plane.width * (b._y - k.ActualRange._x) / (k.ActualRange._y - k.ActualRange._x);

	//std::cout<<"after conversion"<<std::endl;
	//std::cout<<a._x<<"  and   "<<a._y<<std::endl;
	return a;
}

Points convertor::implicitConvert(Points a)
{

	a._x *= 100;
	a._y *= 100;
	a._x += 500;
	a._y += 400;
	return a;
}