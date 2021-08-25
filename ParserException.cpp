#include "include/ParserException.hpp"

INVALIDOPERAND::INVALIDOPERAND(std::string s)
{
    message = s;
}

std::string INVALIDOPERAND::get_message()
{
    return message;
}


INVALIDFORMAT::INVALIDFORMAT(std::string s)
{
    message = s;
}

std::string INVALIDFORMAT::get_message()
{
    return message;
}



