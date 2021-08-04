#include "variable.hpp"

// Constructor
Variable::Variable(char v):_v(v){
    
}

// Get the type variable
TokenType Variable::TypeOf() const{
    return VARIABLE;
}

// Get the value of variable
char Variable::GetVariable(){
    return _v;
}
