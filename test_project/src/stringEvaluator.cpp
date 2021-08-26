#include "stringEvaluator.hpp"
#include <regex>

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
	if (!findEqual(str))
	{
		throw FORMATERROR();
	}
	
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
		unsigned pos;
		for (unsigned i = str.length(); i > 0; i--)
		{
			if (str[i] == '=')
			{
				std::string temp;
				temp.assign(str.begin() + i + 1, str.end());
				std::cout << "temp: " << temp << std::endl;
				//for (size_t i = 0; i < temp.size(); i++)
				if (!StringEvaluator::isNumber(temp))
				{
					throw FORMATERROR();
				}
				
				try
				{
					info.constant = stod(temp);
				}
				catch (...)
				{
					throw FORMATERROR();
				}
				pos = i;
				break;
			}
		}
		info.equation.assign(str.begin(), str.begin() + pos);
		info.type = Implicit;

		//implicit
	}
	if (findEqual(info.equation))
	{
		std::cout << "equal found" << std::endl;
		std::cout << info.equation << std::endl;
		throw FORMATERROR();
		info.type = None;
		info.equation = "";
	}
	return info;
}



bool StringEvaluator::isNumber(const std::string& s)
{
    int nb_point=0;
    for (size_t i=0; i<s.length();i++)
    {
         if (s[i]=='.')
         {
              nb_point++;
         }
         else if (!isdigit(s[i]))
		 {
              return false;
         }
		 else
		 {
			 /* code */
		 }
		 

		 
    }
    if (nb_point<=1)
    {
          return true;
    }
    else
    {
          return false;
    }
}