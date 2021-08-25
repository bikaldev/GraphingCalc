#pragma once

#include <iostream>
//using namespace std;

// Different types of tokens
enum TokenType{OPERAND, OPERATOR, LEFTBRACKET, RIGHTBRACKET, SPACE, FUNCTION, VARIABLE, LETTER, COMMA, OTHER};

class Token{
public:
    
    
    
    // Get the token type
    virtual TokenType TypeOf() const = 0;
};
