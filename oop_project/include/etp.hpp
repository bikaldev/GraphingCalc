#pragma once
#include "points.hpp"
#include "shuntingyard.hpp"
#include "windowsize.hpp"
#include <SFML/Graphics.hpp>

namespace convertor
{
//if y is dependend var
std::vector<Points> Plotxtoy(std::string, WindowSize&);
//if x is dependend var
std::vector<Points> Plotytox(std::string, WindowSize&);
//convert from world coordinates to sfml coordinates.
Points Convert(Points, WindowSize&);
//to convert implictCoordinates
Points implicitConvert(Points);
}
