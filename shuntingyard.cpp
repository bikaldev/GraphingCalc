
#include "shuntingyard.hpp"
#include "ParserException.hpp"
Parser::Parser(std::string s):exp{s}
{
    //this doesn't work
    StringToInfix();
    InfixToPostfix();
}
// Convert a string to an infix queue
void Parser::StringToInfix()
{
	Tokenizer ps(exp);
	//queue<Token*> output;
	string temp;
	char t;
	double d;
	unsigned int left_bracket_num = 0;
	unsigned int right_bracket_num = 0;
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
				infix_expr.push(new Operand(d));
				break;
				// In other cases, convert the parsed string to character
			case token::OPERATOR:
				t = temp[0];
				infix_expr.push(new Operator(t));
				break;
			case token::LEFTBRACKET:
				t = temp[0];
				infix_expr.push(new LeftBracket(t));
				left_bracket_num++;
				break;
			case token::RIGHTBRACKET:
				t = temp[0];
				infix_expr.push(new RightBracket(t));
				right_bracket_num++;
				break;
			
			case token::VARIABLE:
			//we have an exception here dealt using if.
				if (!infix_expr.empty())
				{
					switch (infix_expr.back()->TypeOf())
					{
						//this case works perfectly fine but there seems to be some problem with the variable case used here.
						case token::OPERAND:
							infix_expr.push(new Operator('*'));
							break;
						default:
							break;
					}
				}
			
				
				t = temp[0];
				infix_expr.push(new Variable(t));
				break;
			case token::FUNCTION:
				infix_expr.push(new Function(temp));
				break;
			default:
				break;
		}
	}
	if (left_bracket_num != right_bracket_num)
	{
		throw INVALIDFORMAT("Right or Left Bracket missing in the expression");
	}
	
	//return output;
}

// Convert an infix queue to a postfix queue
//lets raise a error here if the code is incorrect ie. displaced operands.
void Parser::InfixToPostfix()
{
	//queue<Token*> postfix;
	//stack<Token*> s;
	Token* p;
	// While there are still tokens to be read from the input
	while (!(infix_expr.empty()))
	{
		// Pop the token from the input and check its type
		p = infix_expr.front();
		infix_expr.pop();
		switch (p->TypeOf())
		{
				// If it is a number, push into the output queue
			case token::OPERAND: {
				postfix_expr.push(p);
				break;
			}
			case token::VARIABLE: {
				postfix_expr.push(p);
				break;
			}
				// If it is a left bracket, push into the operator stack
			case token::LEFTBRACKET: {
				operator_stack.push(p);
				break;
			}
				// If it is a function, push into the operator stack
			case token::FUNCTION: {
				operator_stack.push(p);
				break;
			}
				// If it is a right bracket, pop all the operators from the operator stack until the left bracket
				// onto the output queue
			case token::RIGHTBRACKET: {
				while (!(operator_stack.empty()) && (operator_stack.top())->TypeOf() != token::LEFTBRACKET)
				{
					postfix_expr.push(operator_stack.top());
					operator_stack.pop();
				}
				operator_stack.pop();
				break;
			}
				// If it is an operator
			case token::OPERATOR: {
				// while ((there is a function at the top of the operator stack)
				// or (there is an operator at the top of the operator stack with greater precedence)
				// or (the operator at the top of the operator stack has equal precedence and is left associative))
				// and (the operator at the top of the operator stack is not a left bracket):
				// Push to the postfix queue
				while (!(operator_stack.empty()) && (((operator_stack.top())->TypeOf() == token::FUNCTION) || (((operator_stack.top())->TypeOf() == token::OPERATOR && (static_cast<Operator*>(operator_stack.top())->getPrecendence() > static_cast<Operator*>(p)->getPrecendence() || (static_cast<Operator*>(operator_stack.top())->getPrecendence() == static_cast<Operator*>(p)->getPrecendence() && !(static_cast<Operator*>(operator_stack.top())->isRightAssociative())))))) && (operator_stack.top())->TypeOf() != token::LEFTBRACKET)
				{
					postfix_expr.push(operator_stack.top());
					operator_stack.pop();
				}
				// After the while loop, push all the operator in the operator stack
				operator_stack.push(p);
				break;
			}
			default:
				break;
		}
	}
	// Push the remaining operators in the operator stack to the postfix queue
	while (!(operator_stack.empty()))
	{
		postfix_expr.push(operator_stack.top());
		operator_stack.pop();
	}
	//return postfix;
}

// Evaluate the postfix queue
double Parser::EvaluatePostfix(double x, double y)
{
	std::queue<Token*>postfix = postfix_expr;
	//stack<Token*> s;
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
				output_stack.push(p);
				break;
			}
			// If the type of the node in the Queue is a variable, push it to the Stack as an Operand
			case token::VARIABLE: {
				switch (static_cast<Variable*>(p)->VariableTypeOf())
				{
					case X:
						output_stack.push(new Operand(x));
						break;
					case Y:
						output_stack.push(new Operand(y));
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
			case token::OTHER:
				break;
			// If the type is an operator, get the operator, pop at the Stack, do the operation then push the result to the Stack
			case token::OPERATOR: {

				if (!output_stack.empty())
				{
					
				try
				{
					if (output_stack.size() == 1)
					{
						//the problem comes here when we use unary operatos.
						right = static_cast<Operand*>(output_stack.top())->GetOperand();
						output_stack.pop();
						output = static_cast<Operator*>(p)->evaluate(left, right);
					}
					// For regular operators
					else
					{
						//this is the place where the error occurs if the operand is the first member used.
						//since there is no term in front of the operand as it is the first term in the solution
						right = static_cast<Operand*>(output_stack.top())->GetOperand();
						output_stack.pop();
						left = static_cast<Operand*>(output_stack.top())->GetOperand();
						output_stack.pop();
						output = static_cast<Operator*>(p)->evaluate(left, right);
					}

				}
				catch(INVALIDOPERAND e)
				{
					std::cerr << e.get_message() << '\n';
				}
				//use this to put x=0
				catch(IMAGINARY)
				{
					//this might be a better option because this ensures that the nothing is drawn. The previous solution only made sure that the terminal point is origin which isn't alwaays true
					//termination of programs might be a better option here.
					output = 1000;
				}
				
				
				output_stack.push(new Operand(output));
				break;
				}
				else
				{
					//perhaps we can throw something here, or create a new way to handle this.
					std::cout<<"this has been handled"<<std::endl;
					break;
				}
				
				//break;
				
			}
			// If the type is a function, pop the operand at the stack and push the result to the Stack
			case token::FUNCTION: {
				switch (static_cast<Function*>(p)->FunctionTypeOf())
				{
					// For function of one argument
					case ftype::ONE_ARGUMENT: {
						right = static_cast<Operand*>(output_stack.top())->GetOperand();
						output_stack.pop();
						output = static_cast<Function*>(p)->evaluate(right);
						break;
					}
					// For function of two arguments (min, max)
					//this might also not be necessary
					case ftype::TWO_ARGUMENT: {
						right = static_cast<Operand*>(output_stack.top())->GetOperand();
						output_stack.pop();
						left = static_cast<Operand*>(output_stack.top())->GetOperand();
						output_stack.pop();
						output = static_cast<Function*>(p)->evaluate(left, right);
						break;
					}
					default:
						break;
				}
				output_stack.push(new Operand(output));
				break;
			}
			default:
				break;
		}
	}
	return static_cast<Operand*>(output_stack.top())->GetOperand();
}


Parser::~Parser()
{
    while (!postfix_expr.empty())
    {
            Token* k = postfix_expr.front();
            delete k;
            k=NULL;
            postfix_expr.pop();
    }
    //it seems a new operator_stack and new output_stack 
    
}
