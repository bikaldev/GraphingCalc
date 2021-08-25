#pragma once

#include "token.hpp"
#include <cmath>

class Operator : public Token
{
public:
	// Constructor
	Operator(char o);

	// Get the type of the operator
	token::TokenType TypeOf() const;

	// Get the type from the string
	token::TokenType getType() const;

	// Get the operator
	char GetOperator();

	// Evaluate the operation
	double evaluate(const double& left, const double& right);

	// Get the precendence from th
	int getPrecendence();

	bool isRightAssociative();

private:
	char _operator;
};
