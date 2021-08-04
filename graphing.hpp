#pragma once

#include <SFML/Graphics.hpp>
#include "windowsize.hpp"
#include "cartesian.hpp"
#include "Line.hpp"
#include <stack>
#include <iostream>
#include <vector>
using namespace std;


// Convert Real World Coordinates to Window Coordinates
//Because real world coordinates and coordinates in SFML are different, we need to convert from real world to window world for display
//sf::Vector2f convertCartesiantoWindow(Cartesian& c, WindowSize& p);
sf::Vector2f convertCartesiantoWindow(Cartesian& c, WindowSize& p);

// Plot all the data from a stack of Cartesian coordinates
//sf::VertexArray plot(WindowSize& p, stack<Cartesian>& c);
sf::VertexArray plot(WindowSize& p, vector<Cartesian>& c);

