#define N_X 50
#define N_Y 50
#define OX (-2+i*dx)
//#define OX(-z + i * dx) this is the code when range is provided by the user
//#define OY(z - j * dy) this is the code when range is provided by the user
#define OY (2-j*dy)
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "line.hpp"
double  h=0.0;
double dx=4/(double)(N_X-1);//2z/(N_X-1)
double dy=4/(double)(N_Y-1);//2z/(N_Y-1)
std::vector<std::vector<double>>data;

double f(double x, double y);    // Function whose contour is to be plotted
int cell(double a, double b, double c, double d);  // Helper ftn to determine cell type from f corner values
void lines(int , int, int, double, double, double, double, sf::RenderWindow &window);  // Helper ftn to draw correct line in a cell
void sendData(std::vector<std::vector<double>>, sf::RenderWindow &window);

void display(sf::RenderWindow &window)
{
	int k=0;
    std::cout<<"i was called"<<std::endl;
    for (int i = 0; i < N_X; i++)
    {
		std::vector<double> temp;
		data.push_back(temp);
        //std::cout<<data[i][1]<<std::endl;
        for (int j = 0; j < N_Y; j++)
        {
	//std::cout<<"\n\n\n\n\n\n\nww"<<data[i][j]<<std::endl;
            data[i].push_back(f(OX,OY));
        }   
    }
	//std::cout<<"i am working as well"<<std::endl;
	//std::cout<<data.size();
	for (int i = 0; i < N_X-1; i++)
    {
        for (int j = 0; j < N_Y-1; j++)
        {
			
			//std::cout<<"so i am working"<<std::endl;
			//if using namespace std is used in the program here we get a refrence to data is ambigious.
            int c = cell(data[i][j],data[i+1][j],data[i][j+1],data[i+1][j+1]);  // return cell type c (0-15)
			lines(c,i,j,data[i][j],data[i+1][j],data[i][j+1],data[i+1][j+1],window);  // draw correct line
        }
        
    }
    
}

//double data[N_X][N_Y]={0};
int cell(double a, double b, double c, double d)
{
	//std::cout<<a<<" and "<<b<<" and "<<c<<" and "<<d<<std::endl;
	//isnt this order incorrect?
    int n=0;
    if (a>h) n+=1;
    if (b>h) n+=8;
    if (c>h) n+=4;
    if (d>h) n+=2;
	//std::cout<<n<<std::endl;
    return n;
}

void draw_one(int n, int i, int j, double a, double b, double c, double d, sf::RenderWindow& window){
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	switch(n){
		case 1:
		case 14:	x1 = OX;
					y1 = OY - (dy * ((h - a) / (c - a)));
					x2 = OX + (dx * ((h - a) / (b - a)));
					y2 = OY;
					//printf("1: (%f, %f)\n", (h - a) / (d - a), (h - a) / (b - a));
					break;
		case 4:
		case 11: 	x1 = OX;
					y1 = OY - (dy * ((h - a) / (c - a)));
					x2 = OX + (dx * ((h - c) / (d - c)));
					y2 = OY - dy;
					//printf("2: (%f, %f)\n", (h - c)/(b - c), (h - c)/(a - c));
					break;
		case 2:
		case 13: 	x1 = OX + dx;
					y1 = OY - (dy * ((h - b) / (d - b)));
					x2 = OX + (dx * ((h - c) / (d - c)));
					y2 = OY - dy;
					//printf("3: (%f, %f)\n", (h - d) / (a - d), (h - d) / (c - d));
					break;
		case 7:
		case 8: 	x1 = OX + dx;
					y1 = OY - (dy * ((h - b) / (d - b)));
					x2 = OX + (dx * ((h - a) / (b - a)));
					y2 = OY;
					//printf("4: (%f, %f)\n", (h - b) / (c - b), (h - b) / (d - b));
					break;
	}
	x1*=100;
	x2*=100;
	y1*=100;
	y2*=100;
	x1+=500;
	x2+=500;
	y1+=500;
	y2+=500;
	std::cout<<x1<< " " <<y1<< " " <<x2<< " " <<y2<<std::endl;
	//lines were beign drawn here
	sf::Vector2f p1{x1, y1};
	sf::Vector2f p2{x2, y2};
	sfLine line(p1,p2,4.f);
    window.draw(line);

}

void draw_opposite(int n, int i, int j, double a, double b, double c, double d, sf::RenderWindow& window){
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	//std::cout<<"i am being called"<<std::endl;
	switch(n){
		case 5:
		case 10:	y1 = OY;
					x1 = OX + (dx * ((h - a) / (b - a)));
					y2 = OY - dy;
					x2 = OX + (dx * ((h - c) / (d - c)));
					break;
		case 6:
		case 9:		x2 = OX;
					y1 = OY - (dy * ((h - b) / (d - b)));
					x1 = OX + dx;
					y2 = OY - (dy * ((h - a) / (c - a)));
					break;
	}
	//lines were drawn here
	x1*=100;
	x2*=100;
	y1*=100;
	y2*=100;
	x1+=500;
	x2+=500;
	y1+=500;
	y2+=500;
	//std::cout<<x1<< " " <<y1<< " " <<x2<< " " <<y2<<std::endl;
    sf::Vector2f p1{x1, y1};
	sf::Vector2f p2{x2, y2};
	sfLine line(p1,p2,3.f);
    window.draw(line);


}

void lines(int n, int i, int j, double a, double b, double c, double d,sf::RenderWindow& window) // Draw correct line
{
   // Your code goes here
   // n is cell type (0-15)
   // i,j specifes which cell
   // a,b,c,d are function values at cell corners (from data array)
	switch(n){
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
		case 10:	draw_opposite(n, i, j, a, b, c, d , window);
					break;
		case 0:
		case 15:	break;
		default:
			//exit(2);
		break;
	}

}
//this returns the equation
double f(double x, double y)
{
	std::cout<<"working here alright"<<std::endl;
    return ((x*x))+(y*y)-4;
}



int main()
{
    sf::RenderWindow window(sf::VideoMode(1000,1000),"SFML works");
    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        display(window);
        window.display();
    

    }
    
}


