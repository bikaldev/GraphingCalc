#include "include/operand.hpp"

// Constructor
Operand::Operand(double o): _operand(o){

}


// Get the type Operand
token::TokenType Operand::TypeOf() const{
    return token::OPERAND;
}

// Get the value of operand
//error at ++6*x-10=0 seg fault
//so double operators can't be used.
//this error ocurrs if operand is the first member of the string
double Operand::GetOperand(){
    return _operand;
}
