#include "column.hpp"

void Column::draw(sf::RenderWindow& window)
{
    //this is the first row and column.
    
    window.draw(*x);
    window.draw(*y);
    
}

void Column::listenforClick(sf::RenderWindow &window)
{
    x->listenForClick(window);
    y->listenForClick(window);
}

void Column::listenforText(sf::Event &event)
{
    x->listenForText(event);
    y->listenForText(event);
}
//perhaps we can add new value to here. 
void Column::getstring()
{
    x_val = stod(x->getString());
    y_val = stod(y->getString());
}

Column::~Column()
{
    //let us delete all the new x and y objects here.
    delete x;
    delete y;
}
