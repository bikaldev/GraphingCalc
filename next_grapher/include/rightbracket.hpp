#pragma once

#include "token.hpp"

class RightBracket: public Token{
public:
    // constructor
    RightBracket(char t);
    
    // Return the type RIGHTBRACKET
    TokenType TypeOf() const;
    
    
    // Get the right bracket
    char GetRightBracket();
private:
    char _t;
    
};
