#pragma once

#include "token.hpp"

class Operand: public Token{
public:
    // Constructor
    Operand(double o);
    
    
    // Get the type Operand
    TokenType TypeOf() const;
    
    // Get the value of operand
    double GetOperand();
    
private:
    double _operand;
};


