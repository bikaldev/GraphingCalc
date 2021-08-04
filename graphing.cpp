
#include "graphing.hpp"
#include "Line.hpp"

// Convert a Real World Coordinate to a Window Coordinate
//Because real world coordinates and coordinates in SFML are different, we need to convert from real world to window world for display
sf::Vector2f convertCartesiantoWindow(Cartesian& c, WindowSize& p){
    
    sf::Vector2f pos;
    
    // Convert into Window world's (x,y) coordinate
    pos.x= p.plane.left + p.plane.width * (c._x - p.Min._x)/(p.Max._x - p.Min._x);
    pos.y= p.plane.top + p.plane.height * (p.Max._y - c._y)/(p.Max._y-p.Min._y);
    
    return pos;
}
/*
// Plot all the data from a stack of Cartesian coordinates
sf::VertexArray plot(WindowSize& p,stack<Cartesian>& c)
{
    sf::VertexArray g;
    // Append each Coordinate to the VertexArray
    while(!c.empty())
    {
        sf::Vector2f pos=convertCartesiantoWindow(c.top(),p);
        g.append(sf::Vertex(pos,sf::Color::Red));
        c.pop();
    }
    
    return g;
}
*/
// Plot all the data from a stack of Cartesian coordinates

/*
sf::VertexArray plot(WindowSize& p,vector<Cartesian>& c)
{
    sf::VertexArray g;
    // Append each Coordinate to the VertexArray
    while(!c.empty())
    {
        sf::Vector2f pos=convertCartesiantoWindow(c.top(),p);
        g.append(sf::Vertex(pos,sf::Color::Red));
        c.pop();
    }
    
    return g;
}

*/

sf::VertexArray plot(WindowSize& p, vector<Cartesian>& c)
{
    sf::VertexArray d;
   //add cordinates to a vector<float>
   while(!c.empty())
   {
       sf::Vector2f Pos = convertCartesiantoWindow(c.back(),p);
       
       d.append(sf::Vertex(Pos, sf::Color::Red));
       c.pop_back();
   }
   
    return d;
}

/*std::vector<sfLine> Lineform(vector<Cartesian> k)
{
    vector<sfLine> m;
    while (!k.empty())
    {
        //this part is the main problem.
        //sf::Vector2f a, b;
        float n, l;
        l=15.f;
        n=10.f;

        Cartesian a = k.back();
        k.pop_back();
        Cartesian b = k.back();
        k.pop_back();
        float c=3.f;
        m.push_back(sfLine(a,b,c));
    }
    return m;
    
}
*/


