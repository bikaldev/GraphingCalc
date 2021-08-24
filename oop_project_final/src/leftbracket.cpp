#include "include/leftbracket.hpp"

// Constructor
LeftBracket::LeftBracket(char t)
{
	_t = t;
}

// Return the type LEFTBRACKET
token::TokenType LeftBracket::TypeOf() const
{
	return token::LEFTBRACKET;
}

// Get the left bracket
char LeftBracket::GetLeftBracket()
{
	return _t;
}
