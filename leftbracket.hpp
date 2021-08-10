#pragma once

#include "token.hpp"

// Class Left Brackets
class LeftBracket: public Token{
public:
    // Constructor
    LeftBracket(char t);

    // Return the type LEFTBRACKET
    token::TokenType TypeOf() const;

    // Print the left bracket
    void Print(ostream& outs = cout) const;

    // Get the left bracket
    char GetLeftBracket();
private:
    char _t;

};

