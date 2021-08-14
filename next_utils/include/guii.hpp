//this is for pointboxes

#pragma once
#include "button.hpp"
#include "textbox.hpp"

class Pointbox : public Button
{
private:
    //here the data to be initialized is a single 
    std::vector<std::vector<Textbox *>> pointboxes;
public:
    
   
};
