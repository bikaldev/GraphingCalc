#pragma once

#include "token.hpp"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

namespace ftype
{
//perhaps we dont need different types of functions and only deal with the same kind ie one argument.
enum FunctionType
{
	ONE_ARGUMENT,
	TWO_ARGUMENT,
	DEFAULT
};

}

class Function : public Token
{
public:
	// Constructor
	Function(string f);

	// Get the type function
	token::TokenType TypeOf() const;

	// Check what kind of function it is
	ftype::FunctionType FunctionTypeOf() const;

	// Get the value of function
	string GetFunction();

	// Evaluate when the function takes one argument
	double evaluate(const double& a);

	// Evaluate when the function takes one argument
	double evaluate(const double& a, const double& b);

private:
	string _function;
	ftype::FunctionType _ftype;
};
