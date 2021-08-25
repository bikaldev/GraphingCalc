#pragma once

#include "token.hpp"

// Class Left Brackets
class LeftBracket: public Token{
public:
    // Constructor
    LeftBracket(char t);
    
    // Return the type LEFTBRACKET
    TokenType TypeOf() const;
    
    // Get the left bracket
    char GetLeftBracket();
private:
    char _t;
    
};