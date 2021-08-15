#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

//only works for 3 types:
// y is dependent and the expression is of the form: y = f(x)
// x is dependent and the expression is of the form: x = f(y)
// the expression is implicit of the form: f(x,y) = 0

enum CurveType
{
	Y_dep,
	X_dep,
	Implicit,
	None
};

struct CurveInfo
{
	CurveType type;
	std::string equation;
	sf::Color color;
};

class StringEvaluator
{
private:
	static bool findEqual(std::string str);
	static std::string removeWhiteSpace(std::string str);

public:
	static CurveInfo evaluate(std::string str);
};

bool StringEvaluator::findEqual(std::string str)
{
	for (int i = 0; i < static_cast<int>(str.length()); i++)
	{
		if (str[i] == '=')
			return true;
	}
	return false;
}

std::string StringEvaluator::removeWhiteSpace(std::string str)
{
	std::string newStr;
	int count = 0;
	std::string temp;
	for (int i = 0; i < static_cast<int>(str.length()); i++)
	{
		if (str[i] != ' ')
		{
			//newStr[count] = str[i];
			temp = str[i];
			newStr.append(temp);
			count++;
		}
	}
	return newStr;
}

CurveInfo StringEvaluator::evaluate(std::string str)
{
	str = removeWhiteSpace(str);
	CurveInfo info;
	if (str.substr(0, 2) == "x=")
	{
		info.equation.assign(str.begin() + 2, str.end());
		info.type = X_dep;
		//x is the dependent variable here
	}
	else if (str.substr(0, 2) == "y=")
	{
		info.equation.assign(str.begin() + 2, str.end());
		info.type = Y_dep;
		//y is the dependent variable here.
		//c=convertor::Plotytox(expr, DefaultWindow);
	}
	else
	{
		std::cout << "Implicit" << std::endl;
		info.equation.assign(str.begin(), str.end() - 2);
		info.type = Implicit;

		//implicit
	}
	if (findEqual(info.equation))
	{
		info.type = None;
		info.equation = "";
	}
	return info;
}
