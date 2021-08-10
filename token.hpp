#pragma once

#include <iostream>
using namespace std;

// Different types of tokens
namespace token
{
enum TokenType
{
	OPERAND,
	OPERATOR,
	LEFTBRACKET,
	RIGHTBRACKET,
	SPACE,
	FUNCTION,
	VARIABLE,
	LETTER,
	COMMA,
	OTHER
};

}

class Token
{
public:
	// Get the token type
	virtual token::TokenType TypeOf() const = 0;
};

/*
#pragma once
//using pragma once here stopped the redifination of class error
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;

class sfLine: public sf::Drawable
{
public:
    sfLine(){}
    sfLine(const sf::Vector2f& point1, const sf::Vector2f& point2, const float &t):
        color(sf::Color::Red), thickness(t), vertices(sf::TriangleStrip, 4)
    {
        sf::Vector2f delta {(point2.x-point1.x),(point2.y-point1.y)};
        float length = sqrtf(delta.x*delta.x + delta.y*delta.y);
        float scale = thickness/(2*length);
        sf::Vector2f radius = {-scale*delta.y, scale*delta.x};
        vertices[0].position = {point1.x -radius.x,point1.y-radius.y};
        vertices[1].position = {point1.x +radius.x,point1.y+radius.y};
        vertices[2].position = {point2.x-radius.x,point2.y-radius.y};
        vertices[3].position = {point2.x +radius.x,point2.y+radius.y};

        for (int i=0; i<4; ++i)
            vertices[i].color = color;
    }
    ~sfLine(){}
private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(vertices, states);
    }


private:
    //sf::VertexArray vertices;
    sf::Color color;
    float thickness;
    sf::VertexArray vertices;
    ///sf::Color color;
};
*/