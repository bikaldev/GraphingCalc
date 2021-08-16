#include "column.hpp"

void Column::draw(sf::RenderWindow& window)
{
    //this is the first row and column.
    x = new Textbox(size, sp_1, "assets/arial.ttf", Type::IP);
    y = new Textbox(size, sp_2, "assets/arial.ttf", Type::IP);
    window.draw(*x);
    window.draw(*y);
    
}

