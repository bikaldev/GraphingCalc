#pragma once

#include "token.hpp"

class Variable: public Token {
public:
    // Constructor
    Variable(char v);
    
    // Get the type variable
    TokenType TypeOf() const;
    
    // Get the value of variable
    char GetVariable();
    
private:
    char _v;
};
