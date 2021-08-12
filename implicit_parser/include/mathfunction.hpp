#pragma once

#include "token.hpp"
#include <cmath>

enum FunctionType {ONE_ARGUMENT, TWO_ARGUMENT, DEFAULT};

class Function: public Token{
public:
    // Constructor
    Function(std::string f);
   
    // Get the type function
    TokenType TypeOf() const;
    
    // Check what kind of function it is
    FunctionType FunctionTypeOf() const;
    
    // Get the value of function
    std::string GetFunction();
    
    // Evaluate when the function takes one argument
    double evaluate(const double& a);
    
    // Evaluate when the function takes one argument
    double evaluate(const double& a, const double& b);
    
private:
    std::string _function;
    FunctionType _ftype;
};

