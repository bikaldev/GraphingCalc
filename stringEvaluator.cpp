#include "stringEvaluator.hpp"

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
//for some reason when x*sin(x) is inputted it displays in implicit form, this needs to be corrected.
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
		//std::cout << "Implicit" << std::endl;
		info.equation.assign(str.begin(), str.end() - 2);
		info.type = Implicit;

		//implicit
	}
	if (findEqual(info.equation))
	{
		std::cout<<"equal not found"<<std::endl;
		throw FORMATERROR();
		info.type = None;
		info.equation = "";
	}
	return info;
}
