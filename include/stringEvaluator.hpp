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

typedef int textboxId;

class FORMATERROR
{
public:
	std::string message()
	{
		return "Wrong Format! Should be either in y = f(x), x = f(y) or f(x,y) = const";
	}
};

struct CurveInfo
{
	CurveType type;
	std::string equation;
	sf::Color color;
	textboxId id;
	double constant;
};

class StringEvaluator
{
private:
	static bool isNumber(const std::string& s);
	static bool findEqual(std::string str);
	static std::string removeWhiteSpace(std::string str);

public:
	static CurveInfo evaluate(std::string str);
};