#pragma once
#include "Grapher.hpp"
#include "button.hpp"
#include "column.hpp"
#include "textbox.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class Gui
{
private:
	enum InputType
	{
		Points_plot,
		Equations_plot
	};
	InputType choice;

	bool btn1_clicked;
	bool btn2_clicked;
	bool btn3_clicked;
	bool btn4_clicked;
	unsigned int btn1_click_count = 0;
	unsigned int btn2_click_count = 0;
	unsigned int btn3_click_count = 0;
	unsigned int btn4_click_count = 0;

	bool add_clicked;
	bool ptn_clicked;
	bool eqn_clicked;
	unsigned int total_click = 0;
	//lets add the buttons stuff right here.
	sf::Vector2f eq_pos { 50.f, 50.f };
	Button eqns;
	Button ptns;

	sf::Vector2f add_pos { 50.f, 600.f };
	Button add;

	float tb_h = 40.f;
	float tb_w = 200.f;
	float sp_x = 50.f;
	float sp_y = 150.f;

	float point_cell_gap = 15.f;
	float pointboxes_gap = 50.f;

	Textbox* tb1;
	Button btn1;
	//we dont need too different variables the same 
	std::string val_1 = " ";


	Textbox* tb2;
	Button btn2;
	std::string val_2 = " ";

	Textbox* tb3;
	Button btn3;
	std::string val_3 = " ";

	Textbox* tb4;
	Button btn4;
	std::string val_4 = " ";

	Button add_col_1;
	Button add_col_2;
	Button add_col_3;
	Button add_col_4;

	Button point_plot_1;
	Button point_plot_2;
	Button point_plot_3;
	Button point_plot_4;

	Button add_button;
	//this needs to be initialized in the init function.
	Column* pointbox0;
	Column* pointbox1;
	Column* pointbox2;
	Column* pointbox3;
	Column* pointbox4;
	Column* pointbox5;
	Column* pointbox6;
	Column* pointbox7;
	Column* pointbox8;
	Column* pointbox9;
	Column* pointbox10;
	Column* pointbox11;
	Column* pointbox12;
	Column* pointbox13;
	Column* pointbox14;
	Column* pointbox15;
	Column* pointbox16;
	Column* pointbox17;
	Column* pointbox18;
	Column* pointbox19;

	Textbox* degree_entry;
	std::string degree_val = "1";

	sf::RenderWindow window;
	Grapher graph;

	bool col_1_added;
	bool col_2_added;
	bool col_3_added;
	bool col_4_added;
	unsigned int col_1_count = 0;
	unsigned int col_2_count = 0;
	unsigned int col_3_count = 0;
	unsigned int col_4_count = 0;

	bool pointbox_added;
	unsigned int pointbox_count = 0;
	unsigned int col_count;
	//unsigned int pointbox_count;

public:
	Gui();
	void main();
	void draw_equations();
	void draw_points();
	void draw_col();
	~Gui();
};