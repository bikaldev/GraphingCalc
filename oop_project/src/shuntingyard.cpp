#include "shuntingyard.hpp"

// Convert a string to an infix queue
queue<Token*> StringToInfix(string s)
{
	ParsedString ps(s);
	queue<Token*> output;
	string temp;
	char t;
	double d;
	// Loop until no other string to parse
	// Each time we get a new token, push to the output queue
	while (!ps.isEmpty())
	{
		temp = ps.nextToken();
		switch (ps.getType())
		{
			case token::OPERAND:

				// Get the number converted from the next string token
				d = ps.getNumber();
				output.push(new Operand(d));
				break;
				// In other cases, convert the parsed string to character
			case token::OPERATOR:
				t = temp[0];
				output.push(new Operator(t));
				break;
			case token::LEFTBRACKET:
				t = temp[0];
				output.push(new LeftBracket(t));
				break;
			case token::RIGHTBRACKET:
				t = temp[0];
				output.push(new RightBracket(t));
				break;
			// When there is SPACE or COMMA, do nothing
			case token::SPACE:
				break;
			case token::COMMA:
				break;
			case token::VARIABLE:
				t = temp[0];
				output.push(new Variable(t));
				break;
			case token::FUNCTION:
				output.push(new Function(temp));
				break;
			default:
				break;
		}
	}
	return output;
}

// Convert an infix queue to a postfix queue
queue<Token*> InfixToPostfix(queue<Token*> infix)
{
	queue<Token*> postfix;
	stack<Token*> s;
	Token* p;
	// While there are still tokens to be read from the input
	while (!(infix.empty()))
	{
		// Pop the token from the input and check its type
		p = infix.front();
		infix.pop();
		switch (p->TypeOf())
		{
				// If it is a number, push into the output queue
			case token::OPERAND: {
				postfix.push(p);
				break;
			}
			case token::VARIABLE: {
				postfix.push(p);
				break;
			}
				// If it is a left bracket, push into the operator stack
			case token::LEFTBRACKET: {
				s.push(p);
				break;
			}
				// If it is a function, push into the operator stack
			case token::FUNCTION: {
				s.push(p);
				break;
			}
				// If it is a right bracket, pop all the operators from the operator stack until the left bracket
				// onto the output queue
			case token::RIGHTBRACKET: {
				while (!(s.empty()) && (s.top())->TypeOf() != token::LEFTBRACKET)
				{
					postfix.push(s.top());
					s.pop();
				}
				s.pop();
				break;
			}
				// If it is an operator
			case token::OPERATOR: {
				// while ((there is a function at the top of the operator stack)
				// or (there is an operator at the top of the operator stack with greater precedence)
				// or (the operator at the top of the operator stack has equal precedence and is left associative))
				// and (the operator at the top of the operator stack is not a left bracket):
				// Push to the postfix queue
				while (!(s.empty()) && (((s.top())->TypeOf() == token::FUNCTION) || (((s.top())->TypeOf() == token::OPERATOR && (static_cast<Operator*>(s.top())->getPrecendence() > static_cast<Operator*>(p)->getPrecendence() || (static_cast<Operator*>(s.top())->getPrecendence() == static_cast<Operator*>(p)->getPrecendence() && !(static_cast<Operator*>(s.top())->isRightAssociative())))))) && (s.top())->TypeOf() != token::LEFTBRACKET)
				{
					postfix.push(s.top());
					s.pop();
				}
				// After the while loop, push all the operator in the operator stack
				s.push(p);
				break;
			}
			default:
				break;
		}
	}
	// Push the remaining operators in the operator stack to the postfix queue
	while (!(s.empty()))
	{
		postfix.push(s.top());
		s.pop();
	}
	return postfix;
}

// Evaluate the postfix queue
double EvaluatePostfix(queue<Token*> postfix, double x, double y)
{
	stack<Token*> s;
	Token* p;
	double left = 0, right = 0, output = 0;

	while (!(postfix.empty()))
	{
		p = postfix.front();
		postfix.pop();
		switch (p->TypeOf())
		{
				// If the type of the node in the Queue is an operand, push it to the Stack
			case token::OPERAND: {
				s.push(p);
				break;
			}
			// If the type of the node in the Queue is a variable, push it to the Stack as an Operand
			case token::VARIABLE: {
				switch (static_cast<Variable*>(p)->VariableTypeOf())
				{
					case X:
						s.push(new Operand(x));
						break;
					case Y:
						s.push(new Operand(y));
						break;
					default:
						break;
				}
				break;
			}
			case token::RIGHTBRACKET:
				break;
			case token::LEFTBRACKET:
				break;
			case token::LETTER:
				break;
			case token::SPACE:
				break;
			case token::COMMA:
				break;
			case token::OTHER:
				break;
			// If the type is an operator, get the operator, pop at the Stack, do the operation then push the result to the Stack
			case token::OPERATOR: {
				// For unary operators
				if (s.size() == 1)
				{
					right = static_cast<Operand*>(s.top())->GetOperand();
					s.pop();
					output = static_cast<Operator*>(p)->evaluate(left, right);
				}
				// For regular operators
				else
				{
					right = static_cast<Operand*>(s.top())->GetOperand();
					s.pop();
					left = static_cast<Operand*>(s.top())->GetOperand();
					s.pop();
					output = static_cast<Operator*>(p)->evaluate(left, right);
				}

				s.push(new Operand(output));
				break;
			}
			// If the type is a function, pop the operand at the stack and push the result to the Stack
			case token::FUNCTION: {
				switch (static_cast<Function*>(p)->FunctionTypeOf())
				{
					// For function of one argument
					case ftype::ONE_ARGUMENT: {
						right = static_cast<Operand*>(s.top())->GetOperand();
						s.pop();
						output = static_cast<Function*>(p)->evaluate(right);
						break;
					}
					// For function of two arguments (min, max)
					case ftype::TWO_ARGUMENT: {
						right = static_cast<Operand*>(s.top())->GetOperand();
						s.pop();
						left = static_cast<Operand*>(s.top())->GetOperand();
						s.pop();
						output = static_cast<Function*>(p)->evaluate(left, right);
						break;
					}
					default:
						break;
				}
				s.push(new Operand(output));
				break;
			}
			default:
				break;
		}
	}
	return static_cast<Operand*>(s.top())->GetOperand();
}
