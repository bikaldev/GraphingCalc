#include "grapher.hpp"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000.f, 1000.f), "Graphing Calculator");
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
    //most of my problems start here.
    std::vector<Grapher*> graphs;

    //here we add the equations fist 
    //lets add strings
    std::vector<std::string> equations;
    std::string a[3];

    //a[0] = "x^2";
    //a[1] = "x^3";
    a[0] = "x";
    //a[3] = "x^2+2*x";
    //a[4] = "x+5";
    a[1] = "-x";
    a[2] = "sin(x)";

    for(int i=0;i<3;i++)
    {
        equations.push_back(a[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        //Grapher graph(equations[i]);
        //i believe this line of code causes seg fault.
        graphs.push_back(new Grapher(equations[i]));
    }
    while (!graphs.empty())
    {
        graphs.back()->init();
        graphs.back()->main(window);
        graphs.pop_back();
    }
    
    window.display();
    }
    
}
