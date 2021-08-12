#include "leftbracket.hpp"

// Constructor
LeftBracket::LeftBracket(char t){
    _t = t;
}

// Return the type LEFTBRACKET
TokenType LeftBracket::TypeOf() const{
    return LEFTBRACKET;
}



// Get the left bracket
char LeftBracket::GetLeftBracket(){
    return _t;
}
