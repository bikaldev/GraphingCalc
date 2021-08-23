#include "mathfunction.hpp"

// Constructor
Function::Function(string f) :
	_function(f)
{
}

// Get the type function
token::TokenType Function::TypeOf() const
{
	return token::FUNCTION;
}

// Get the value of function
string Function::GetFunction()
{
	return _function;
}

// Check what kind of function it is
ftype::FunctionType Function::FunctionTypeOf() const
{
	if (_function == "sin" || _function == "cos" || _function == "tan" || _function == "cot" || _function == "sec" || _function == "csc" || _function == "exp" || _function == "ln")
		return ftype::ONE_ARGUMENT;
	else if (_function == "min" || _function == "max")
		return ftype::TWO_ARGUMENT;
	else
		return ftype::DEFAULT;
}

// Evaluate when the function takes one argument
double Function::evaluate(const double& a)
{
	if (this->_function == "sin")
		return sin(a);
	else if (_function == "cos")
		return cos(a);
	else if (_function == "tan")
		//the tangent curves are of variable length whatever we do here.
		return tan(a);
	else if (_function == "cot")
		return 1 / tan(a);
	else if (_function == "sec")
		return 1 / cos(a);
	else if (_function == "csc")
		return 1 / sin(a);
	else if (_function == "exp")
		return exp(a);
	else if (_function == "ln")
		return log(a);
	else
		return 0;
}

// Evaluate when the function takes two arguments
double Function::evaluate(const double& a, const double& b)
{
	if (_function == "max")
		return max(a, b);
	else if (_function == "min")
		return min(a, b);
	else
		return 0;
}
