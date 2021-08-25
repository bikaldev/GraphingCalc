#pragma once

// Struct for cartesian coordinates, which contains x and y coordinates
class Points {
public:
    double _x;
    double _y;
    // Default constructor
    Points():_x{0},_y{0}{}
    
    // Constructor which takes two coordinate arguments
    Points(double x, double y):_x(x),_y(y){}
};
