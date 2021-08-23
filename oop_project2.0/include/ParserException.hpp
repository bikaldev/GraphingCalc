#pragma once
#include <iostream>
#include <sstream>

class INVALIDOPERAND
{
    private:
        std::string message;
    public:
        INVALIDOPERAND(std::string s);
        std::string get_message();

};

class IMAGINARY{};
//we dont really need this one right now
class INVALIDFORMAT
{
    private:
        std::string message;
    public:
        INVALIDFORMAT(std::string s);
        std::string get_message();
};

