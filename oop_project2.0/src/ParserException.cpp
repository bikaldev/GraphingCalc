#include "ParserException.hpp"

std::string INVALIDOPERAND::message()
{
    return "[ERROR]: The operand used is incorrect";
}


std::string INVALIDFORMAT::message()
{
    return "[ERROR]: The input format used is incorrect";
}

