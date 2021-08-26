#include "ImplicitPlotter.hpp"

ImplicitPlotter::ImplicitPlotter(WindowSize w, sf::Vector2f org, double c, sf::Color col)
{
	win = w;
	origin = org;
	color = col;
	h = c;
	N_X = 200;
	N_Y = 200;
	dx = 40 / (double)(N_X - 1); //2z/(N_X-1)
	dy = 40 / (double)(N_Y - 1); //2z/(N_Y-1)
}
//this function does the main conversion
double ImplicitPlotter::map(double value, double istart, double istop, double ostart, double ostop)
{
	return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}

//increase GridNumber with change in amplitude
void ImplicitPlotter::increaseGridNumber() {
	if(N_X>=500)
		return;
	N_X += 50;
	N_Y += 50;
}
void ImplicitPlotter::decreaseGridNumber() {
	if(N_X <= 200)
		return;
	N_X -=50;
	N_Y -= 50;
}
//we need to change stuff here as well
void ImplicitPlotter::display(std::string s, sf::RenderWindow& window)
{
	//if the parser is initiailized here then we can not use in later properly.
	std::string imp_exp = s;
	Parser parse(imp_exp);
	//double z;
	//std::queue<Token*> infix = StringToInfix(imp_exp);
	//std::queue<Token*> postfix = InfixToPostfix(infix);
	//std::cout << "i was called" << std::endl;
	for (int i = 0; i < N_X; i++)
	{
		std::vector<double> temp;
		data.push_back(temp);
		//std::cout<<data[i][1]<<std::endl;
		for (int j = 0; j < N_Y; j++)
		{
			//std::cout<<"\n\n\n\n\n\n\nww"<<data[i][j]<<std::endl;
			data[i].push_back(parse.EvaluatePostfix(OX, OY));
		}
	}
	// std::cout << "i am working as well" << std::endl;
	//std::cout<<data.size();
	//this is used to display
	for (int i = 0; i < N_X - 1; i++)
	{
		for (int j = 0; j < N_Y - 1; j++)
		{

			//std::cout<<"so i am working"<<std::endl;
			//if using namespace std is used in the program here we get a refrence to data is ambigious.
			int c = cell(data[i][j], data[i + 1][j], data[i][j + 1], data[i + 1][j + 1]);			// return cell type c (0-15)
			lines(c, i, j, data[i][j], data[i + 1][j], data[i][j + 1], data[i + 1][j + 1], window); // draw correct line
		}
	}
}

//double data[N_X][N_Y]={0};
int ImplicitPlotter::cell(double a, double b, double c, double d)
{
	//std::cout<<a<<" and "<<b<<" and "<<c<<" and "<<d<<std::endl;
	//isnt this order incorrect?
	int n = 0;
	if (a > h)
		n += 1;
	if (b > h)
		n += 8;
	if (c > h)
		n += 4;
	if (d > h)
		n += 2;
	//std::cout<<n<<std::endl;
	
	
	return n;
}

void ImplicitPlotter::draw_one(int n, int i, int j, double a, double b, double c, double d, sf::RenderWindow& window)
{
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	switch (n)
	{
		case 1:
		case 14:
			x1 = OX;
			y1 = OY - (dy * ((h - a) / (c - a)));
			x2 = OX + (dx * ((h - a) / (b - a)));
			y2 = OY;
			//printf("1: (%f, %f)\n", (h - a) / (d - a), (h - a) / (b - a));
			break;
		case 4:
		case 11:
			x1 = OX;
			y1 = OY - (dy * ((h - a) / (c - a)));
			x2 = OX + (dx * ((h - c) / (d - c)));
			y2 = OY - dy;
			//printf("2: (%f, %f)\n", (h - c)/(b - c), (h - c)/(a - c));
			break;
		case 2:
		case 13:
			x1 = OX + dx;
			y1 = OY - (dy * ((h - b) / (d - b)));
			x2 = OX + (dx * ((h - c) / (d - c)));
			y2 = OY - dy;
			//printf("3: (%f, %f)\n", (h - d) / (a - d), (h - d) / (c - d));
			break;
		case 7:
		case 8:
			x1 = OX + dx;
			y1 = OY - (dy * ((h - b) / (d - b)));
			x2 = OX + (dx * ((h - a) / (b - a)));
			y2 = OY;
			//printf("4: (%f, %f)\n", (h - b) / (c - b), (h - b) / (d - b));
			break;
		default:
			break;
	}

	x1 = map(x1, win.ActualRange._x, win.ActualRange._y, win.MagnifiedRange._x, win.MagnifiedRange._y) + origin.x;
	y1 = map(y1, win.ActualRange._x, win.ActualRange._y, win.MagnifiedRange._x, win.MagnifiedRange._y) + origin.y;
	x2 = map(x2, win.ActualRange._x, win.ActualRange._y, win.MagnifiedRange._x, win.MagnifiedRange._y) + origin.x;
	y2 = map(y2, win.ActualRange._x, win.ActualRange._y, win.MagnifiedRange._x, win.MagnifiedRange._y) + origin.y;

	sf::Vector2f p1 { static_cast<float>(x1), static_cast<float>(y1) }, p2 { static_cast<float>(x2), static_cast<float>(y2) };
	sfLine obj(p1, p2, 3.f, color);
	window.draw(obj);
}

void ImplicitPlotter::draw_opposite(int n, int i, int j, double a, double b, double c, double d, sf::RenderWindow& window)
{
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	//std::cout<<"i am being called"<<std::endl;
	switch (n)
	{
		case 5:
		case 10:
			y1 = OY;
			x1 = OX + (dx * ((h - a) / (b - a)));
			y2 = OY - dy;
			x2 = OX + (dx * ((h - c) / (d - c)));
			break;
		case 6:
		case 9:
			x2 = OX;
			y1 = OY - (dy * ((h - b) / (d - b)));
			x1 = OX + dx;
			y2 = OY - (dy * ((h - a) / (c - a)));
			break;
		default:
			break;
	}

	x1 = map(x1, win.ActualRange._x, win.ActualRange._y, win.MagnifiedRange._x, win.MagnifiedRange._y) + origin.x;
	y1 = map(y1, win.ActualRange._x, win.ActualRange._y, win.MagnifiedRange._x, win.MagnifiedRange._y) + origin.y;
	x2 = map(x2, win.ActualRange._x, win.ActualRange._y, win.MagnifiedRange._x, win.MagnifiedRange._y) + origin.x;
	y2 = map(y2, win.ActualRange._x, win.ActualRange._y, win.MagnifiedRange._x, win.MagnifiedRange._y) + origin.y;

	sf::Vector2f p1 { static_cast<float>(x1), static_cast<float>(y1) }, p2 { static_cast<float>(x2), static_cast<float>(y2) };
	sfLine obj(p1, p2, 3.f, color);
	window.draw(obj);
}

void ImplicitPlotter::lines(int n, int i, int j, double a, double b, double c, double d, sf::RenderWindow& window) // Draw correct line
{
	// Your code goes here
	// n is cell type (0-15)
	// i,j specifes which cell
	// a,b,c,d are function values at cell corners (from data array)
	switch (n)
	{
		case 1:
		case 2:
		case 4:
		case 7:
		case 8:
		case 11:
		case 13:
		case 14:
			draw_one(n, i, j, a, b, c, d, window);
			break;
		case 5:
		case 6:
		case 9:
		case 10:
			draw_opposite(n, i, j, a, b, c, d, window);
			break;
		case 0:
		case 15: break;
		default:
			//exit(2);
			break;
	}
}