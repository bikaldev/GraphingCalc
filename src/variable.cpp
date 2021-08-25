#include "variable.hpp"

// Constructor
Variable::Variable(char v) :
	_v(v)
{
}

// Get the type variable
token::TokenType Variable::TypeOf() const
{
	return token::VARIABLE;
}

VariableType Variable::VariableTypeOf() const
{
	if (_v == 'x')
	{
		return X;
	}
	// else if (_v == 'y')
	// {
	// 	return Y;
	// }
	else
	{
		return Y;
	}
}

// Get the value of variable
char Variable::GetVariable()
{
	return _v;
}
