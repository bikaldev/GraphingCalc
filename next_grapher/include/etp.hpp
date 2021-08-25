#pragma once
#include <SFML/Graphics.hpp>
#include "shuntingyard.hpp"
#include "points.hpp"
#include "windowsize.hpp"



namespace convertor{
//if y is dependend var
std::vector <Points> Plotxtoy(std::string, WindowSize&);
//if x is dependend var
std::vector <Points> Plotytox(std::string, WindowSize&);
//convert from world coordinates to sfml coordinates.
Points Convert(Points, WindowSize&);
//to convert implictCoordinates
Points implicitConvert(Points);
}

