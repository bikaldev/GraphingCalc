#include "grapher.hpp"
#include "line.hpp"
#include "implicit_plotter.hpp"


void Grapher::init()
{
    //thesse coordinates decide where on the window is the object to be viewd.
    MAX = 10;
    MIN = -10;
    INCREMENTS = 0.01;
    DefaultWindow.Max = Points(MAX,MAX);
    DefaultWindow.Min = Points(MIN,MIN);
    DefaultWindow.plane.width = 500;
    DefaultWindow.plane.height = 500;
    DefaultWindow.plane.top=250;
    DefaultWindow.plane.left=400;

    //initialize the window
    window.create(sf::VideoMode(1000,1000),"Graphing Calculator");
    //perhaps we can add all the equations at once here
    exp = "sin(x)";
}

void Grapher::main()
{
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    window.clear(sf::Color::Black);  
     //let's display an implicit function form here.
    //lets edit this part later.
    //implicit_display(window, DefaultWindow);
    c=convertor::Plotytox(exp, DefaultWindow);
    sf::Vector2f p1, p2;
    
    for (size_t i = 0; i < c.size()-1; i++)
    {
        p1.x=c[i]._x;
        p1.y=c[i]._y;

        p2.x=c[i+1]._x;
        p2.y=c[i+1]._y;
        sfLine line(p1, p2, 3.f);
        window.draw(line);

        
        
    }
    
    imp_display(window, DefaultWindow);
    window.display();
    }
    
}
