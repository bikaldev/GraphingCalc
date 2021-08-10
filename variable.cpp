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

// Get the value of variable
char Variable::GetVariable()
{
	return _v;
}
