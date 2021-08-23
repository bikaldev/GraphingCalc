#pragma once
//this needs to include more features so that zoom can be enabled.
#include <SFML/Graphics.hpp>
#include "points.hpp"

//Struct to set size for the window plane                                                        
struct WindowSize {
public:
    //window plane                                                                               
    sf::FloatRect plane;

    // Max and min coordinates                                                                   
    Points Max;
    Points Min;
};