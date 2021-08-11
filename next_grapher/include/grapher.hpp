#pragma once
//this the program where graphing is done
#include "etp.hpp"
#include "points.hpp"
#include "windowsize.hpp"

class Grapher
{
private:
    double MAX, MIN, INCREMENTS;
    WindowSize DefaultWindow;
    sf::RenderWindow window;
    
    std::vector<Points> c;
    //vector<Points> d;
    std::string exp;

public:
    void init();
    void main();
};




