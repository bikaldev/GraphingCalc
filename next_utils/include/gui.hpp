#pragma once
#include "button.hpp"
#include "textbox.hpp"

//this only creates one button and text field composite.
//what to do for pointboxs
//perhaps we dont need the constructor here
//lets use this class to only plot one unit for eqaution plotting.
class EqnPlot: public Button , public Textbox
{
    private:
        //static int previous_count
        //float tb_h;
        //float tb_w;
        //Textbox textboxes;
        //Button buttons;

    public:
        EqnPlot(){}
        //this initializes now we have to draw the base class members
        EqnPlot(float a, float b, std::string c , sf::Vector2f d, sf::Vector2f e, std::string f):Button(a, b, c), Textbox(d, e, f){}

};
