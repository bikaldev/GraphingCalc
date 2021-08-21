#include "operator.hpp"

// Constructor
Operator::Operator(char o) :
	_operator(o)
{
}

// Return the type OPERATOR
token::TokenType Operator::TypeOf() const
{
	return token::OPERATOR;
}

// Get the operator
char Operator::GetOperator()
{
	return _operator;
}

// Evaluate the operation
double Operator::evaluate(const double& left, const double& right)
{
	double output;
	switch (_operator)
	{
		case '+': {
			output = left + right;
			break;
		}
		case '-': {
			output = left - right;
			break;
		}
		case '*': {
			output = left * right;
			break;
		}
		case '/': {
			output = left / right;
			break;
		}
		case '^': {
			output = pow(left, right);
		}
		default:
			break;
	}
	return output;
}

// Get the precendence from different types of operators
int Operator::getPrecendence()
{
	int p;
	switch (_operator)
	{
		case '+':
		case '-':
			p = 1;
			break;

		case '*':
		case '/':
			p = 2;
			break;

		case '^':
			p = 3;
			break;
		default:
			break;
	}
	return p;
}

// Return true if the operator is right associative (only ^)
bool Operator::isRightAssociative()
{
	return (getPrecendence() == 3);
}
