#pragma once

#include <string>
#include <iostream>
#include "token.hpp"

//using namespace std;

class ParsedString {
public:
    // Constructor
    ParsedString(std::string s);
    
    // Separate the next token from the string
    std::string nextToken();
    
    // Convert a string to a number
    void convertToNumber(std::string s);
    
    // Convert other types from strings
    TokenType convertToOtherTypes(std::string s);
    
    // Get number from the conversion
    double getNumber();
    
    //Get the type of the current parsed string
    TokenType getType();
    
    // Categorize the type of string being parsed currently
    TokenType stringType();
    
    // Check if the there is any string to parse
    bool isEmpty();
    
private:
    // Store other types of strings like operators, left, right brackets
    std::string _s;
    
    // Store the operand
    double _d;
    
    // current type of string being parsed
    TokenType _type;
    
    // Position of the character being read in the current string
    int _pos;
    
    // These string constants are lists of tokens that we can compare to find out the type of a specific token
    const std::string operands = "0123456789.";
    const std::string operators = "*+-/^";
    const std::string left = "(";
    const std::string right = ")";
    const std::string space = " ";
    const std::string comma = ",";
    const std::string letters = "abcdefghijklmnopqrstuvwxyz";
};


