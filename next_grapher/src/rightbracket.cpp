#include "rightbracket.hpp"

// Constructor
RightBracket::RightBracket(char t){
    _t = t;
}

// Return the type RIGHTBRACKET
TokenType RightBracket::TypeOf() const{
    return RIGHTBRACKET;
}

// Get the right bracket
char RightBracket::GetRightBracket(){
    return _t;
}
