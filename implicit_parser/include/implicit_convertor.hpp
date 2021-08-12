#pragma once
#include "windowsize.hpp"
#include "points.hpp"
#include <iostream>

Points implicit_convertor(Points& p1, WindowSize& k)
{
    std::cout<<"this is the data before conversion"<<std::endl;
    std::cout<<p1._x<<"\t"<<p1._y<<std::endl;
    Points a;
    a._x= k.plane.left + k.plane.width * (p1._x - k.Min._x)/(k.Max._x - k.Min._x);
    a._y= k.plane.top + k.plane.height * (k.Max._y - p1._y)/(k.Max._y-k.Min._y);
    //p1._x*=100;
    //p1._y*=100;
    //p1._x+=500;
    //p1._y+=500;
    std::cout<<"this is the data after conversion"<<std::endl;
    std::cout<<a._x<<"\t"<<a._y<<std::endl;
    //std::cout<<"after conversion"<<std::endl;
    //std::cout<<a._x<<"  and   "<<a._y<<std::endl;
    return a;
}
//this function is better than the other functions.
double  map(double value, double istart, double istop, double ostart,
                    double ostop) {
  return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}

