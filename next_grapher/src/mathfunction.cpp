#include "mathfunction.hpp"

// Constructor
Function::Function(std::string f): _function(f){
    
}

// Get the type function
TokenType Function::TypeOf() const{
    return FUNCTION;
}

// Get the value of function
std::string Function::GetFunction(){
    return _function;
}

// Check what kind of function it is
FunctionType Function::FunctionTypeOf() const{
    if (_function == "sin" || _function == "cos" || _function == "tan" || _function == "cot" ||
        _function == "sec" || _function == "csc" || _function == "exp" || _function == "ln")
        return ONE_ARGUMENT;
    else if (_function == "min" || _function == "max")
        return TWO_ARGUMENT;
    else
        return DEFAULT;
}

// Evaluate when the function takes one argument
double Function::evaluate(const double& a){
    if (_function == "sin")
        return sin(a);
    else if (_function == "cos")
        return cos(a);
    else if (_function == "tan")
        return tan(a);
    else if (_function == "cot")
        return 1/tan(a);
    else if (_function == "sec")
        return 1/cos(a);
    else if (_function == "csc")
        return 1/sin(a);
    else if (_function == "exp")
        return exp(a);
    else if (_function == "ln")
        return log(a);
    else
        return 0;
}

// Evaluate when the function takes two arguments
//perhaps we dont need this part
double Function::evaluate(const double& a, const double& b){
    if (_function == "max")
        return std::max(a, b);
    else if (_function == "min")
        return std::min(a, b);
    else
        return 0;
}
