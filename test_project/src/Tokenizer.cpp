#include "Tokenizer.hpp"
#include "ParserException.hpp"

// Constructor
Tokenizer::Tokenizer(string s)
{
	_type = token::OTHER;
	_s = s;
	_pos = 0;
	_d = 0;
}

// Separate the next token from the string and increment _pos depending on the length of each token
string Tokenizer::nextToken()
{
	string s;
	token::TokenType currentType = stringType();
	switch (currentType)
	{
		case token::OPERAND: {
			unsigned int dot_num = 0;
			// parse before the letter that is not a valid operand
			//this works now we have to search for dots.
			int j = _s.find_first_not_of(operands, _pos);
			//search for the occurance of .. here.
			std::string dot = _s.substr(_pos, j - _pos);
			for (size_t i = 0; i < dot.size(); i++)
			{
				if (dot[i] == '.')
				{
					dot_num++;
				}
				
			}
			if (dot_num > 1)
			{
				throw INVALIDOPERAND("Input a valid operand");
			}
			
			
			//std::cout<<dot<<std::endl;

			s.assign(_s, _pos, j - _pos);
			convertToNumber(s);
			_pos += j - _pos;
			break;
		}

		// For operator, as it only has one character, so parse only one character out of the next string
		//if the previous terms are also an operator we need to think about it.
		case token::OPERATOR: {
			s.assign(_s, _pos, 1);
			_pos++;
			break;
		}
			// For left bracket, as it only has one character, so parse only one character out of the next string
		case token::LEFTBRACKET: {
			s.assign("(");
			_pos++;
			break;
		}
			// For right bracket, as it only has one character, so parse only one character out of the next string
		case token::RIGHTBRACKET: {
			s.assign(")");
			_pos++;
			break;
		}
		
			// For string that contains letters, it can be a function or a variable. We parse the substring
		case token::LETTER: {
			// j is the last position in the substring that is not a letter
			int j = _s.find_first_not_of(letters, _pos);

			s.assign(_s, _pos, j - _pos);

			// then Convert the substring with letters into appropriate types
			_type = convertToOtherTypes(s);
			_pos += j - _pos;
			break;
		}
		
		case token::OTHER:
			break;
		default:
			break;
	}
	return s;
}

// Convert a string to a number
void Tokenizer::convertToNumber(string s)
{
	_d = stod(s);
}

// Convert letter type string to appropriate token types
token::TokenType Tokenizer::convertToOtherTypes(string s)
{
	if (s == "x" || s == "y")
		_type = token::VARIABLE;
	else if (s == "sin" || s == "cos" || s == "tan" || s == "cot" || s == "sec" || s == "csc" || s == "ln" || s == "exp" || s == "min" || s == "max")
		_type = token::FUNCTION;
	else
	{
		throw INVALIDFORMAT("Invalid funtion or variable name.");
	}
	

	return _type;
}
// Get number from the conversion from a double type
double Tokenizer::getNumber()
{
	return _d;
}

// Get the type of the current parsed string
token::TokenType Tokenizer::getType()
{
	return _type;
}

// Categorize the type of string being parsed currently, by checking if character at a given position fits the characters in the private constant strings
token::TokenType Tokenizer::stringType()
{
	int operand_pos = operands.find(_s[_pos]);
	int operator_pos = operators.find(_s[_pos]);
	int left_pos = left.find(_s[_pos]);
	int right_pos = right.find(_s[_pos]);
	int letter_pos = letters.find(_s[_pos]);
	//-1 is the resutl if nothing is found
	if (operand_pos != -1)
		_type = token::OPERAND;

	else if (operator_pos != -1)
		_type = token::OPERATOR;

	else if (left_pos != -1)
		_type = token::LEFTBRACKET;

	else if (right_pos != -1)
		_type = token::RIGHTBRACKET;

	else if (letter_pos != -1)
		_type = token::LETTER;

	return _type;
}

// Check if there is any string to parse
bool Tokenizer::isEmpty()
{
	if (static_cast<int>(_pos) < 0)
	{
		return true;
	}
	return static_cast<int>(_pos) >= static_cast<int>(_s.length());
}
