#include "operand.hpp"

// Constructor
Operand::Operand(double o): _operand(o){
    
}


// Get the type Operand
TokenType Operand::TypeOf() const{
    return OPERAND;
}

// Get the value of operand
double Operand::GetOperand(){
    return _operand;
}
