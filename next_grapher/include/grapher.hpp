#pragma once
//this the program where graphing is done
#include "etp.hpp"
#include "points.hpp"
#include "windowsize.hpp"
//perhps we should make multiple of these
//a certain string for a certain onject.
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
    Grapher(){}
    Grapher(std::string k):exp{k}{}
    void init();
    void main(sf::RenderWindow& window);
};






