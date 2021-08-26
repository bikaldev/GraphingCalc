#pragma once

#include "token.hpp"
#include <iostream>
#include <string>

//using namespace std;

class Tokenizer
{
public:
	// Constructor
	Tokenizer(string s);

	// Separate the next token from the string
	string nextToken();

	// Convert a string to a number
	void convertToNumber(string s);

	// Convert other types from strings
	token::TokenType convertToOtherTypes(string s);

	// Get number from the conversion
	double getNumber();

	//Get the type of the current parsed string
	token::TokenType getType();

	// Categorize the type of string being parsed currently
	token::TokenType stringType();

	// Check if the there is any string to parse
	bool isEmpty();

private:
	// Store other types of strings like operators, left, right brackets
	string _s;

	// Store the operand
	double _d;

	// current type of string being parsed
	token::TokenType _type;

	// Position of the character being read in the current string
	int _pos;

	// These string constants are lists of tokens that we can compare to find out the type of a specific token
	const string operands = "0123456789.";
	const string operators = "*+-/^";
	const string left = "(";
	const string right = ")";
	const string letters = "abcdefghijklmnopqrstuvwxyz";
};
