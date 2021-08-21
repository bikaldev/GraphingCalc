
#pragma once

#include "points.hpp"
#include <SFML/Graphics.hpp>

//Struct to set size for the window plane
struct WindowSize
{
public:
	//window plane
	sf::FloatRect plane;

	// // Max and min coordinates
	// Points Max;
	// Points Min;

	//Updated:
	Points ActualRange;
	Points MagnifiedRange;
};
