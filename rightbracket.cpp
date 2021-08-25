#include "include/rightbracket.hpp"

// Constructor
RightBracket::RightBracket(char t)
{
	_t = t;
}

// Return the type RIGHTBRACKET
token::TokenType RightBracket::TypeOf() const
{
	return token::RIGHTBRACKET;
}

// Get the right bracket
char RightBracket::GetRightBracket()
{
	return _t;
}
