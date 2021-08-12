#include "grapher.hpp"
#include "line.hpp"
#include "implicit_plotter.hpp"


void Grapher::init()
{
    //thesse coordinates decide where on the window is the object to be viewd.
    //this has been done for every graph
    //if max and min are altered with zoom isn't produced but the graph dost reduced. The effect is total graph layout and not just the main graph.
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
    //window.create(sf::VideoMode(1000,1000),"Graphing Calculator");
    //perhaps we can add all the equations at once here
}

void Grapher::main(sf::RenderWindow &window)
{
    
     //let's display an implicit function form here.
    //lets edit this part later.
    //implicit_display(window, DefaultWindow);
    //lets put the checker here
    
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
    
    //imp_display(window, DefaultWindow);
    //window.display();
}

void Grapher::stringEvaluator(std::string str)
{
    std::string expr;
    if (expr[0]=='x')
    {
        //x is the dependent variable here
        //perhaps we should use a different function here.
        c=convertor::Plotytox(expr, DefaultWindow);
    }
    else if (expr[0]=='y')
    {
        //y is the dependent variable here. 
        c=convertor::Plotytox(expr, DefaultWindow);
    }
    //if (expr.Substring(0, 5) == "implicit")
    //there is no member called substring
    else if (expr.substr(0, 8) == "implicit")
    {
        //this is for the implicit part
    }
    else if (expr.substr(0, 6) == "points")
    {
        //this is for the input in points
    }
    else
    {
        std::cout<<"the format in which you entered doesn't work"<<std::endl;
    }
    
    
    
    
    
    //this line of code to remove the initial two parts of the code.
    //this line of code only works for explicit functions.
    expr.assign(str.begin()+2, str.end());
}
    

