#pragma once

#include <SFML/Graphics.hpp>
#include "cartesian.hpp"

//Struct to set size for the window plane
struct WindowSize {
public:
    //window plane
    sf::FloatRect plane;
    
    // Max and min coordinates
    Cartesian Max;
    Cartesian Min;
};

