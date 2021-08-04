#include "calculator.hpp"

// Initialize all the variables and the window plane
void Calculator::init(){
    // Initialize variables
    MAX = 10;
    MIN = -10;
    INCREMENT = 0.001;
    
    // Set up default plane, this cant be altered with or else the value changes
    DefaultWindow.Max = Cartesian(MAX,MAX);
    DefaultWindow.Min = Cartesian(MIN,MIN);
    DefaultWindow.plane.width = 1500;
    DefaultWindow.plane.height = 1500;
     
    
     
     // Set up the window
    window.create(sf::VideoMode(1500, 1500), "Graphing calculator");
    //window.setVerticalSyncEnabled(true);
    
    // Initialize the string
    s = "(x^2)";
}

// Execute the graphing
void Calculator::main(){
    
    // Handle events in window
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            switch (event.type) {
            // Close the window
                case sf::Event::Closed:
                    window.close();
                    break;
                
            }
        }
        
        // After evaluating the value from string, store all the Cartesian coordinates in a VertexArray v;
        c = PlotExpression(s, MIN, MAX, INCREMENT);
        sf::VertexArray v = plot(DefaultWindow, c);
        vector<Cartesian> d;
        d=PlotExpressionn("y^2",MIN,MAX,INCREMENT);
        sf::VertexArray w = plot(DefaultWindow, d);
        //vector<sfLine>a = Lineform(v);
        //c.Clear();(this is were to clear the stack c and enter new elements, it seems this might not be necessary)
        //ploting again
        //c = PlotExpression("sin(x)", MIN, MAX, INCREMENT);
        //sf::VertexArray w = plot(DefaultWindow, c);
        
        
        // Clear the window
        window.clear(sf::Color::Black);
        
        window.draw(v);
        window.draw(w);
        window.display();
        
       
    }
}

// Evaluate a string expression, with x-coordinate from low to high, and store corresponding coordinates into a stack of Cartesian coordinates
vector<Cartesian> Calculator::PlotExpression(string expression, double low, double high, double increments){
    //instead of making a stack perhpas we should make a vector here.
    //we might not need to make the cartesian coordinates as well.
    vector<Cartesian> c;
    queue<Token*> infix = StringToInfix(expression);
    queue<Token*> postfix = InfixToPostfix(infix);

    for (double i = low; i <= high; i+= increments)
        c.push_back(Cartesian(i,EvaluatePostfix(postfix,i)));
    return c;
}

vector<Cartesian> Calculator::PlotExpressionn(string expression, double low, double high, double increments){
    //instead of making a stack perhpas we should make a vector here.
    //we might not need to make the cartesian coordinates as well.
    vector<Cartesian> c;
    queue<Token*> infix = StringToInfix(expression);
    queue<Token*> postfix = InfixToPostfix(infix);

    for (double i = low; i <= high; i+= increments)
        c.push_back(Cartesian(EvaluatePostfix(postfix,i),i));
    return c;
}

/*
vector<Cartesian> Calculator::PlotExpression(string expression, double low, double high, double increment)
{
    vector<Cartesian> c;
    queue<Token*> infix = StringToInfix(expression);
    queue<Token*> postfix = InfixToPostfix(infix);
    for (double i = low; i <= high; i+= increment)
    {
        c.push_back(Cartesian(i,EvaluatePostfix(postfix,i)));
    }
    return c;
    
}

*/




