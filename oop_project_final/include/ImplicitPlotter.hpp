
// #define N_X 200
// #define N_Y 200
#define OX (-20 + i * dx)
//#define OX(-z + i * dx) this is the code when range is provided by the user
//#define OY(z - j * dy) this is the code when range is provided by the user
#define OY (20 - j * dy)
#include "BezierQuad.hpp"
#include "points.hpp"
#include "Parser.hpp"
#include "windowsize.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>

class ImplicitPlotter
{
private:
	int N_X;
	int N_Y;
	std::vector<std::vector<double>> data;
	sf::Vector2f origin;
	WindowSize win;
	sf::Color color;
	double h;
	double dx;
	double dy;
	//perhaps we can add stuff here.
	//we need to add a string here.

	double map(double value, double istart, double istop, double ostart, double ostop);
	//double f(double x, double y, std::queue<Token*>);									 // Function whose contour is to be plotted
	int cell(double a, double b, double c, double d);									 // Helper ftn to determine cell type from f corner values
	void lines(int, int, int, double, double, double, double, sf::RenderWindow& window); // Helper ftn to draw correct line in a cell
	void sendData(std::vector<std::vector<double>>, sf::RenderWindow& window);
	void draw_one(int n, int i, int j, double a, double b, double c, double d, sf::RenderWindow& window);
	void draw_opposite(int n, int i, int j, double a, double b, double c, double d, sf::RenderWindow& window);

public:
	ImplicitPlotter() = default;
	ImplicitPlotter(WindowSize w, sf::Vector2f org, double c = 0.0, sf::Color col = sf::Color::Red);
	//the string has been taken here.
	void display(std::string s, sf::RenderWindow& window);
	void increaseGridNumber();
	void decreaseGridNumber();
};