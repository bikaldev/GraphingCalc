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
			//std::cout<<output<<std::endl;
			break;
		}
		case '-': {
			output = left - right;
			//std::cout<<"i am being used"<<std::endl;
			//std::cout<<output<<std::endl;
			break;
		}
		case '*': {
			output = left * right;
			break;
		}
		case '/': {
			if (right == 0)
			{
				throw INVALIDOPERAND("Error! Can't divide by ZERO");
			}
			output = left / right;
			break;
		}
		case '^': {
			output = pow(left, right);
			if (left == 0 && right == 0)
			{
				//perhaps we can right the answer to change
				throw INVALIDOPERAND("Error! Can't use ZERO in both power");
			}
			//add condition for sqrt root and negative number
			if (left < 0 && right == 0.5)
			{
				throw IMAGINARY{};
				
			}
			
			
		}
		default:
			break;
	}
	return output;
}
//perhaps we can convert this into a map and it should be easier to evaluate the expression.
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
