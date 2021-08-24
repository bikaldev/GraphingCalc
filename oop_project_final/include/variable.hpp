#pragma once

#include "token.hpp"

//in the function part this is needed becuase evaluation is done differently.
enum VariableType
{
	X,
	Y
};

class Variable : public Token
{
public:
	// Constructor
	Variable(char v);

	// Get the type variable
	token::TokenType TypeOf() const;

	//get what variable it is
	VariableType VariableTypeOf() const;

	// Get the value of variable
	char GetVariable();

private:
	char _v;
};
