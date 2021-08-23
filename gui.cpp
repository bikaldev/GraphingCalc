#include "gui.hpp"

Gui::Gui()
{
	//these are for buttons
	tb1 = new Textbox(sf::Vector2f { tb_w, tb_h }, sf::Vector2f { sp_x, sp_y }, "assets/arial.ttf");
	tb2 = new Textbox(sf::Vector2f { tb_w, tb_h }, sf::Vector2f { sp_x, sp_y + tb_h + 40.f }, "assets/arial.ttf");
	tb3 = new Textbox(sf::Vector2f { tb_w, tb_h }, sf::Vector2f { sp_x, sp_y + tb_h * 2 + 40.f * 2 }, "assets/arial.ttf");
	tb4 = new Textbox(sf::Vector2f { tb_w, tb_h }, sf::Vector2f { sp_x, sp_y + tb_h * 3 + 40.f * 3 }, "assets/arial.ttf");

	pointbox[0] = new Column(sf::Vector2f { 50.f, 150.f }, "assets/arial.ttf");
	pointbox[1] = new Column(sf::Vector2f { 115.f, 150.f }, "assets/arial.ttf");
	pointbox[2] = new Column(sf::Vector2f { 180.f, 150.f }, "assets/arial.ttf");
	pointbox[3] = new Column(sf::Vector2f { 245.f, 150.f }, "assets/arial.ttf");
	pointbox[4] = new Column(sf::Vector2f { 310.f, 150.f }, "assets/arial.ttf");
	pointbox[5] = new Column(sf::Vector2f { 50.f, 250.f }, "assets/arial.ttf");
	pointbox[6] = new Column(sf::Vector2f { 115.f, 250.f }, "assets/arial.ttf");
	pointbox[7] = new Column(sf::Vector2f { 180.f, 250.f }, "assets/arial.ttf");
	pointbox[8] = new Column(sf::Vector2f { 245.f, 250.f }, "assets/arial.ttf");
	pointbox[9] = new Column(sf::Vector2f { 310.f, 250.f }, "assets/arial.ttf");
	pointbox[10] = new Column(sf::Vector2f { 50.f, 350.f }, "assets/arial.ttf");
	pointbox[11] = new Column(sf::Vector2f { 115.f, 350.f }, "assets/arial.ttf");
	pointbox[12] = new Column(sf::Vector2f { 180.f, 350.f }, "assets/arial.ttf");
	pointbox[13] = new Column(sf::Vector2f { 245.f, 350.f }, "assets/arial.ttf");
	pointbox[14] = new Column(sf::Vector2f { 310.f, 350.f }, "assets/arial.ttf");
	pointbox[15] = new Column(sf::Vector2f { 50.f, 450.f }, "assets/arial.ttf");
	pointbox[16] = new Column(sf::Vector2f { 115.f, 450.f }, "assets/arial.ttf");
	pointbox[17] = new Column(sf::Vector2f { 180.f, 450.f }, "assets/arial.ttf");
	pointbox[18] = new Column(sf::Vector2f { 245.f, 450.f }, "assets/arial.ttf");
	pointbox[19] = new Column(sf::Vector2f { 310.f, 450.f }, "assets/arial.ttf");

	window.create(sf::VideoMode(1280.0f, 720.0f), "Graph Layout", sf::Style::Default);
	graph = Grapher(sf::Vector2f(1280.0f, 720.0f), sf::Vector2f(0.0f, 0.0f));
	//for equations
	eqns.setLabel("Equations");
	eqns.Create();
	eqns.setPosition(eq_pos.x, eq_pos.y);
	//for points
	ptns.setLabel("Points");
	ptns.Create();
	ptns.setPosition(eq_pos.x + eqns.width() + 25.f, eq_pos.y);
	//for adding
	add.setLabel("Add");
	add.Create();
	add.setPosition(add_pos.x, add_pos.y);
	//first eqn plotter

	btn1.setLabel("Plot");
	btn1.Create();
	btn1.setPosition(sp_x + tb_w + 25.f, sp_y);
	//second eqn plotter

	btn2.setLabel("Plot");
	btn2.Create();
	btn2.setPosition(sp_x + tb_w + 25.f, sp_y + tb_h + 40.f);
	//third eqn plotter

	btn3.setLabel("Plot");
	btn3.Create();
	btn3.setPosition(sp_x + tb_w + 25.f, sp_y + tb_h * 2 + 40.f * 2);
	//fourth eqn plotter
	//Textbox tb4(sf::Vector2f{tb_w, tb_h}, sf::Vector2f{sp_x, sp_y+tb_h*3+40.f*3},"assets/arial.ttf");
	btn4.setLabel("Plot");
	btn4.Create();
	btn4.setPosition(sp_x + tb_w + 25.f, sp_y + tb_h * 3 + 40.f * 3);

	//////////////////////////////////////////
	//the data from here on is on the points plot
	//////////////////////////////////////////
	add_col_1.setLabel("Add Points");
	add_col_1.Create();
	add_col_1.setPosition(400.f, 140.f);

	point_plot_1.setLabel("Plot");
	point_plot_1.Create();
	point_plot_1.setPosition(400.f, 190.f);

	add_col_2.setLabel("Add Points");
	add_col_2.Create();
	add_col_2.setPosition(400.f, 240.f);

	point_plot_2.setLabel("Plot");
	point_plot_2.Create();
	point_plot_2.setPosition(400.f, 290.f);

	add_col_3.setLabel("Add Points");
	add_col_3.Create();
	add_col_3.setPosition(400.f, 340.f);

	point_plot_3.setLabel("Plot");
	point_plot_3.Create();
	point_plot_3.setPosition(400.f, 390.f);

	add_col_4.setLabel("Add Points");
	add_col_4.Create();
	add_col_4.setPosition(400.f, 440.f);

	point_plot_4.setLabel("Plot");
	point_plot_4.Create();
	point_plot_4.setPosition(400.f, 490.f);

	add_button.setLabel("Add");
	add_button.Create();
	add_button.setPosition(50.f, 600.f);

	//Error handling elements initialization
	error_msg = "";
	error.setString(error_msg);
	error.setPosition(sf::Vector2f(0.3 * VIEW_WIDTH, 0.95 * VIEW_WIDTH));
	error.setFillColor(sf::Color::Red);
	error.setCharacterSize(25);

	//now we create pointboxes
	//four different pointboxes need to be created
}

void Gui::main()
{

	while (window.isOpen())
	{

		window.clear();
		graph.drawLayout(window, true);
		graph.draw(window);
		graph.listenToStaticEvents(window);
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			tb1->listenForText(evnt);
			tb2->listenForText(evnt);
			tb3->listenForText(evnt);
			tb4->listenForText(evnt);

			//for some reason this is not working
			pointbox[0]->listenforText(evnt);
			pointbox[1]->listenforText(evnt);
			pointbox[2]->listenforText(evnt);
			pointbox[3]->listenforText(evnt);
			pointbox[4]->listenforText(evnt);
			pointbox[5]->listenforText(evnt);
			pointbox[6]->listenforText(evnt);
			pointbox[7]->listenforText(evnt);
			pointbox[8]->listenforText(evnt);
			pointbox[9]->listenforText(evnt);
			pointbox[10]->listenforText(evnt);
			pointbox[11]->listenforText(evnt);
			pointbox[12]->listenforText(evnt);
			pointbox[13]->listenforText(evnt);
			pointbox[14]->listenforText(evnt);
			pointbox[15]->listenforText(evnt);
			pointbox[16]->listenforText(evnt);
			pointbox[17]->listenforText(evnt);
			pointbox[18]->listenforText(evnt);
			pointbox[19]->listenforText(evnt);

			graph.listenToLazyEvent(evnt, window);
			switch (evnt.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				default:
					break;
			}
		}

		eqns.listen(window);
		ptns.listen(window);

		if (eqns.clicked == true)
		{
			eqn_clicked = true;
			choice = Equations_plot;
		}

		if (ptns.clicked == true)
		{
			ptn_clicked = true;
			choice = Points_plot;
		}
		//let us write the code that changes the position between two points.
		//i think they need to be in the same else if structure to work
		if (eqn_clicked == true || ptn_clicked == true)
		{
			if (choice == Equations_plot)
			{
				draw_equations();
			}
			else if (choice == Points_plot)
			{
				draw_points();
			}
		}

		window.draw(eqns.Sprite);
		window.draw(eqns.Label);
		window.draw(ptns.Sprite);
		window.draw(ptns.Label);

		window.draw(error);

		window.display();
	}
}

void Gui::draw_equations()
{
	//parts that are needed to draw the equations.
	btn1.listen(window);
	tb1->listenForClick(window);
	add.listen(window);

	if (btn1.clicked == true)
	{
		//here if edited the previous plot remains as well this needs to be taken care of
		btn1_clicked = true;
		btn1_click_count++;
		try
		{
			graph.addCurve(tb1->getString(), 1);
		}
		catch (FORMATERROR e)
		{
			error_msg = e.message();
		}
	}
	if (btn2.clicked == true)
	{
		//here if edited the previous plot remains as well this needs to be taken care of
		btn2_clicked = true;
		btn2_click_count++;
		try
		{
			graph.addCurve(tb2->getString(), 2);
		}
		catch (FORMATERROR e)
		{
			error_msg = e.message();
		}
	}
	if (btn3.clicked == true)
	{
		//here if edited the previous plot remains as well this needs to be taken care of
		btn3_clicked = true;
		btn3_click_count++;
		try
		{
			graph.addCurve(tb3->getString(), 3);
		}
		catch (FORMATERROR e)
		{
			error_msg = e.message();
		}
	}
	if (btn4.clicked == true)
	{
		//here if edited the previous plot remains as well this needs to be taken care of
		btn4_clicked = true;
		btn4_click_count++;
		try
		{
			graph.addCurve(tb4->getString(), 4);
		}
		catch (FORMATERROR e)
		{
			error_msg = e.message();
		}
	}

	if (add.clicked == true)
	{
		total_click++;
		add_clicked = true;
	}

	if (add_clicked == true)
	{

		if (total_click == 1)
		{

			window.draw(*tb2);
			window.draw(btn2.Sprite);
			window.draw(btn2.Label);
			btn2.listen(window);
			tb2->listenForClick(window);
		}
		else if (total_click == 2)
		{
			window.draw(*tb2);
			window.draw(btn2.Sprite);
			window.draw(btn2.Label);
			btn2.listen(window);
			tb2->listenForClick(window);
			window.draw(*tb3);
			window.draw(btn3.Sprite);
			window.draw(btn3.Label);
			btn3.listen(window);
			tb3->listenForClick(window);
		}
		else if (total_click == 3 || total_click > 3)
		{
			window.draw(*tb2);
			window.draw(btn2.Sprite);
			window.draw(btn2.Label);
			btn2.listen(window);
			tb2->listenForClick(window);
			window.draw(*tb3);
			window.draw(btn3.Sprite);
			window.draw(btn3.Label);
			btn3.listen(window);
			tb3->listenForClick(window);
			window.draw(*tb4);
			window.draw(btn4.Sprite);
			window.draw(btn4.Label);
			btn4.listen(window);
			tb4->listenForClick(window);
		}
		else
		{
			/* code */
			//do nothing
		}
	}
	//lets make this displayable only in the points part of the code
	window.draw(*tb1);
	window.draw(btn1.Sprite);
	window.draw(btn1.Label);

	window.draw(add.Sprite);
	window.draw(add.Label);
}

void Gui::draw_points()
{

	//std::cout<<"lets add stuff later"<<std::endl;
	//the dimensions of point box need t be changed
	//perhaps it might be a better idea to just have three inputs for now.
	add_button.listen(window);

	add_col_1.listen(window);
	add_col_2.listen(window);
	add_col_3.listen(window);
	add_col_4.listen(window);

	point_plot_1.listen(window);
	point_plot_2.listen(window);
	point_plot_3.listen(window);
	point_plot_4.listen(window);

	//this adds new columns
	if (add_col_1.clicked == true)
	{
		col_1_count++;
		col_1_added = true;
	}
	if (add_col_2.clicked == true)
	{
		col_2_count++;
		col_2_added = true;
	}
	if (add_col_3.clicked == true)
	{
		col_3_count++;
		col_3_added = true;
	}
	if (add_col_4.clicked == true)
	{
		col_4_count++;
		col_4_added = true;
	}

	if (add_button.clicked == true)
	{
		pointbox_count++;
		pointbox_added = true;
		// switch (pointbox_count)
		// {
		// 	case 0:
		// 		col_1_added = true;
		// 		break;
		// 	case 1:
		// 		col_2_added = true;
		// 		break;
		// 	case 2:
		// 		col_3_added = true;
		// 		break;
		// 	case 3:
		// 		col_4_added = true;
		// 		break;
		// 	default:
		// 		pointbox_count = 3;
		// 		break;
		// }
	}

	pointbox[0]->draw(window);
	pointbox[0]->listenforClick(window);

	if (pointbox_added == true)
	{
		if (pointbox_count == 1)
		{
			//first element of the second pointbox
			window.draw(add_col_2.Sprite);
			window.draw(add_col_2.Label);
			window.draw(point_plot_2.Sprite);
			window.draw(point_plot_2.Label);
			pointbox[5]->draw(window);
			pointbox[5]->listenforClick(window);
		}

		if (pointbox_count == 2)
		{
			window.draw(add_col_2.Sprite);
			window.draw(add_col_2.Label);
			window.draw(point_plot_2.Sprite);
			window.draw(point_plot_2.Label);
			window.draw(add_col_3.Sprite);
			window.draw(add_col_3.Label);
			window.draw(point_plot_3.Sprite);
			window.draw(point_plot_3.Label);
			pointbox[5]->draw(window);
			pointbox[5]->listenforClick(window);
			pointbox[10]->draw(window);
			pointbox[10]->listenforClick(window);
		}

		if (pointbox_count == 3 || pointbox_count > 3)
		{
			window.draw(add_col_2.Sprite);
			window.draw(add_col_2.Label);
			window.draw(point_plot_2.Sprite);
			window.draw(point_plot_2.Label);
			window.draw(add_col_3.Sprite);
			window.draw(add_col_3.Label);
			window.draw(point_plot_3.Sprite);
			window.draw(point_plot_3.Label);
			window.draw(add_col_4.Sprite);
			window.draw(add_col_4.Label);
			window.draw(point_plot_4.Sprite);
			window.draw(point_plot_4.Label);

			pointbox[5]->draw(window);
			pointbox[5]->listenforClick(window);
			pointbox[10]->draw(window);
			pointbox[10]->listenforClick(window);
			pointbox[15]->draw(window);
			pointbox[15]->listenforClick(window);
		}
		else
		{
			//draw nothing
		}
	}

	if (col_1_added == true)
	{

		if (col_1_count > 4)
			col_1_count = 4;
		for (unsigned i = 1; i < 1 + col_1_count; i++)
		{
			pointbox[i]->draw(window);
			pointbox[i]->listenforClick(window);
		}
	}

	if (col_2_added == true)
	{

		if (col_2_count > 4)
			col_2_count = 4;
		for (unsigned i = 6; i < 6 + col_2_count; i++)
		{
			pointbox[i]->draw(window);
			pointbox[i]->listenforClick(window);
		}
	}

	if (col_3_added == true)
	{
		if (col_3_count > 4)
			col_3_count = 4;
		for (unsigned i = 11; i < 11 + col_3_count; i++)
		{
			pointbox[i]->draw(window);
			pointbox[i]->listenforClick(window);
		}
	}

	if (col_4_added == true)
	{
		if (col_4_count > 4)
			col_4_count = 4;
		for (unsigned i = 16; i < 16 + col_4_count; i++)
		{
			pointbox[i]->draw(window);
			pointbox[i]->listenforClick(window);
		}
	}

	//Point is sent to the grapher to ger marked in the graph and the points to be fitted.
	if (point_plot_1.clicked == true)
	{
		if (col_1_added == true)
		{
			if (col_1_count > 4)
				col_1_count = 4;
			for (unsigned i = 0; i <= col_1_count; i++)
			{
				pointbox[i]->getPoint();
				if (pointbox[i]->isInvalid() == true)
				{
					//handle the error of invalid
				}
				if (!pointbox[i]->isEmpty() && !pointbox[i]->isInvalid())
				{
					graph.takePoint(pointbox[i]->getX(), pointbox[i]->getY());
				}
			}
			//the degree from the degree field has to be sent as an argument:
			// graph.fitPoints(degree);
			graph.fitPoints();
		}
	}
	if (point_plot_2.clicked == true)
	{
		if (col_2_added == true)
		{
			if (col_2_count > 4)
				col_2_count = 4;
			for (unsigned i = 0; i <= 5 * 1 + col_2_count; i++)
			{
				pointbox[i]->getPoint();
				if (pointbox[i]->isInvalid() == true)
				{
					//handle the error of invalid
				}
				if (!pointbox[i]->isEmpty() && !pointbox[i]->isInvalid())
				{
					graph.takePoint(pointbox[i]->getX(), pointbox[i]->getY());
				}
			}
			graph.fitPoints();
		}
	}
	if (point_plot_3.clicked == true)
	{
		if (col_3_added == true)
		{
			if (col_3_count > 4)
				col_3_count = 4;
			for (unsigned i = 0; i <= 5 * 2 + col_3_count; i++)
			{
				pointbox[i]->getPoint();
				if (pointbox[i]->isInvalid() == true)
				{
					//handle the error of invalid
				}
				if (!pointbox[i]->isEmpty() && !pointbox[i]->isInvalid())
				{
					graph.takePoint(pointbox[i]->getX(), pointbox[i]->getY());
				}
			}
			graph.fitPoints();
		}
	}
	if (point_plot_4.clicked == true)
	{
		if (col_4_added == true)
		{
			if (col_4_count > 4)
				col_4_count = 4;
			for (unsigned i = 0; i <= 5 * 3 + col_4_count; i++)
			{
				pointbox[i]->getPoint();
				if (pointbox[i]->isInvalid() == true)
				{
					//handle the error of invalid
				}
				if (!pointbox[i]->isEmpty() && !pointbox[i]->isInvalid())
				{
					graph.takePoint(pointbox[i]->getX(), pointbox[i]->getY());
				}
			}
			graph.fitPoints();
		}
	}

	window.draw(add_button.Sprite);
	window.draw(add_button.Label);
	window.draw(add_col_1.Sprite);
	window.draw(add_col_1.Label);
	window.draw(point_plot_1.Sprite);
	window.draw(point_plot_1.Label);
}

Gui::~Gui()
{
	//perhaps we should make a vector of this
	delete tb1;
	delete tb2;
	delete tb3;
	delete tb4;

	//perhaps we should make a vector of this
	for (int i = 0; i < 20; i++)
	{
		delete pointbox[i];
	}
}
