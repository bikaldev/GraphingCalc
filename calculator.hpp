#pragma once
#include <SFML/Graphics.hpp>

//#include "stack.hpp"
//#include "queue.hpp"
#include <stack>
#include <queue>
#include <vector>
#include "graphing.hpp"
#include "shuntingyard.hpp"

class Calculator{
public:
    // Initialize all the variables and the window plane
    void init();
    
    // Execute the graphing
    void main();
private:
    WindowSize DefaultWindow;
    sf::RenderWindow window;
    
    // Stack c contains all the Cartesian coordinate vertices
    //stack<Cartesian> c;
    vector<Cartesian>c; 

    // String that will be put into the equation
    string s;
    
    double MAX = 10;
    double MIN = -10;
    double INCREMENT = 0.001;
    
    // Evaluate a string expression, with x-coordinate from low to high, and store corresponding coordinates into a stack of Cartesian coordinates
    //nothing needs to be changed here except for maybe the use of vector instead of stack
    
    //stack<Cartesian> PlotExpression(string expression, double low, double high, double increments);
    vector<Cartesian> PlotExpression(string expression, double low, double high, double increments);
    vector<Cartesian> PlotExpressionn(string expression, double low, double high, double increments);
    //plot the obtained data using line with thickness entity
    //vector<sfLine> Lineform(vector<Cartesian> a);
   
};


