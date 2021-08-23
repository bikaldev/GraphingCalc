#include "gui.hpp"

Gui::Gui()
{
	//these are for buttons
	tb1 = new Textbox(sf::Vector2f { tb_w, tb_h }, sf::Vector2f { sp_x, sp_y }, "assets/arial.ttf");
	tb2 = new Textbox(sf::Vector2f { tb_w, tb_h }, sf::Vector2f { sp_x, sp_y + tb_h + 40.f }, "assets/arial.ttf");
	tb3 = new Textbox(sf::Vector2f { tb_w, tb_h }, sf::Vector2f { sp_x, sp_y + tb_h * 2 + 40.f * 2 }, "assets/arial.ttf");
	tb4 = new Textbox(sf::Vector2f { tb_w, tb_h }, sf::Vector2f { sp_x, sp_y + tb_h * 3 + 40.f * 3 }, "assets/arial.ttf");

	pointbox0 = new Column(sf::Vector2f { 50.f, 150.f }, "assets/arial.ttf");
	pointbox1 = new Column(sf::Vector2f { 115.f, 150.f }, "assets/arial.ttf");
	pointbox2 = new Column(sf::Vector2f { 180.f, 150.f }, "assets/arial.ttf");
	pointbox3 = new Column(sf::Vector2f { 245.f, 150.f }, "assets/arial.ttf");
	pointbox4 = new Column(sf::Vector2f { 310.f, 150.f }, "assets/arial.ttf");
	pointbox5 = new Column(sf::Vector2f { 50.f, 250.f }, "assets/arial.ttf");
	pointbox6 = new Column(sf::Vector2f { 115.f, 250.f }, "assets/arial.ttf");
	pointbox7 = new Column(sf::Vector2f { 180.f, 250.f }, "assets/arial.ttf");
	pointbox8 = new Column(sf::Vector2f { 245.f, 250.f }, "assets/arial.ttf");
	pointbox9 = new Column(sf::Vector2f { 310.f, 250.f }, "assets/arial.ttf");
	pointbox10 = new Column(sf::Vector2f { 50.f, 350.f }, "assets/arial.ttf");
	pointbox11 = new Column(sf::Vector2f { 115.f, 350.f }, "assets/arial.ttf");
	pointbox12 = new Column(sf::Vector2f { 180.f, 350.f }, "assets/arial.ttf");
	pointbox13 = new Column(sf::Vector2f { 245.f, 350.f }, "assets/arial.ttf");
	pointbox14 = new Column(sf::Vector2f { 310.f, 350.f }, "assets/arial.ttf");
	pointbox15 = new Column(sf::Vector2f { 50.f, 450.f }, "assets/arial.ttf");
	pointbox16 = new Column(sf::Vector2f { 115.f, 450.f }, "assets/arial.ttf");
	pointbox17 = new Column(sf::Vector2f { 180.f, 450.f }, "assets/arial.ttf");
	pointbox18 = new Column(sf::Vector2f { 245.f, 450.f }, "assets/arial.ttf");
	pointbox19 = new Column(sf::Vector2f { 310.f, 450.f }, "assets/arial.ttf");

	degree_entry = new Textbox(sf::Vector2f{40.f, 20.f}, sf::Vector2f{250.f, 550.f}, "assets/arial.ttf");

	window.create(sf::VideoMode(1280, 720), "Graph Layout", sf::Style::Default);
	graph = Grapher(1280.0f, sf::Vector2f(0.0f, 0.0f));
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
			pointbox0->listenforText(evnt);
			pointbox1->listenforText(evnt);
			pointbox2->listenforText(evnt);
			pointbox3->listenforText(evnt);
			pointbox4->listenforText(evnt);
			pointbox5->listenforText(evnt);
			pointbox6->listenforText(evnt);
			pointbox7->listenforText(evnt);
			pointbox8->listenforText(evnt);
			pointbox9->listenforText(evnt);
			pointbox10->listenforText(evnt);
			pointbox11->listenforText(evnt);
			pointbox12->listenforText(evnt);
			pointbox13->listenforText(evnt);
			pointbox14->listenforText(evnt);
			pointbox15->listenforText(evnt);
			pointbox16->listenforText(evnt);
			pointbox17->listenforText(evnt);
			pointbox18->listenforText(evnt);
			pointbox19->listenforText(evnt);

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
		btn1_click_count ++ ;
		//graph.addCurve(tb1->getString(), 1);
	}
	if (btn2.clicked == true)
	{
		//here if edited the previous plot remains as well this needs to be taken care of
		btn2_clicked = true;
		btn2_click_count ++ ;
		//graph.addCurve(tb2->getString(), 2);
	}
	if (btn3.clicked == true)
	{
		//here if edited the previous plot remains as well this needs to be taken care of
		btn3_clicked = true;
		btn3_click_count ++ ;
		//graph.addCurve(tb3->getString(), 3);
	}
	if (btn4.clicked == true)
	{
		//here if edited the previous plot remains as well this needs to be taken care of
		btn4_clicked = true;
		btn4_click_count ++ ;
		//graph.addCurve(tb4->getString(), 4);
	}

	if (add.clicked == true)
	{
		total_click++;
		add_clicked = true;
	}
	//this code just undrawed an already drawn button.
	//this is the exact code to implement switching.
	//we might encounter one problem here.
	if (btn1_clicked == true)
	{
		//we can check for new updates in the code.
		//check if the click count is more than one
		//if so check if the old string and new string are different then delete the old string and use the new one.
		if (btn1_click_count == 1)
		{
			val_1 = tb1->getString();
			graph.addCurve(val_1, 1);
		}
		//perhaps this code might work itself or atleast work for the first time, after which this code probably doesn't work.
		if (btn1_click_count > 1 && val_1 != tb1->getString())
		{
			//write the formula to delete the curve here.
			val_1 = tb1->getString();
			graph.addCurve(val_1, 1);
		}
		
		
	}

	if (btn2_clicked == true)
	{
		//we can check for new updates in the code.
		//check if the click count is more than one
		//if so check if the old string and new string are different then delete the old string and use the new one.
		if (btn2_click_count == 1)
		{
			val_2 = tb2->getString();
			graph.addCurve(val_2, 2);
		}
		//perhaps this code might work itself or atleast work for the first time, after which this code probably doesn't work.
		if (btn2_click_count > 1 && val_2 != tb2->getString())
		{
			val_2 = tb2->getString();
			graph.addCurve(val_2, 2);
		}
		
		
	}

	if (btn3_clicked == true)
	{
		//we can check for new updates in the code.
		//check if the click count is more than one
		//if so check if the old string and new string are different then delete the old string and use the new one.
		if (btn3_click_count == 1)
		{
			val_3 = tb3->getString();
			graph.addCurve(val_3, 3);
		}
		//perhaps this code might work itself or atleast work for the first time, after which this code probably doesn't work.
		if (btn3_click_count > 1 && val_3 != tb3->getString())
		{
			val_3 = tb3->getString();
			graph.addCurve(val_3, 3);
		}
		
		
	}

	if (btn4_clicked == true)
	{
		//we can check for new updates in the code.
		//check if the click count is more than one
		//if so check if the old string and new string are different then delete the old string and use the new one.
		if (btn4_click_count == 1)
		{
			val_4 = tb4->getString();
			graph.addCurve(val_4, 1);
		}
		//perhaps this code might work itself or atleast work for the first time, after which this code probably doesn't work.
		if (btn4_click_count > 1 && val_4 != tb4->getString())
		{
			val_4 = tb4->getString();
			graph.addCurve(val_4, 1);
		}
		
		
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
	}

	pointbox0->draw(window);
	pointbox0->listenforClick(window);

	if (pointbox_added == true)
	{
		if (pointbox_count == 1)
		{
			//first element of the second pointbox
			window.draw(add_col_2.Sprite);
			window.draw(add_col_2.Label);
			window.draw(point_plot_2.Sprite);
			window.draw(point_plot_2.Label);
			pointbox5->draw(window);
			pointbox5->listenforClick(window);
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
			pointbox5->draw(window);
			pointbox5->listenforClick(window);
			pointbox10->draw(window);
			pointbox10->listenforClick(window);
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

			pointbox5->draw(window);
			pointbox5->listenforClick(window);
			pointbox10->draw(window);
			pointbox10->listenforClick(window);
			pointbox15->draw(window);
			pointbox15->listenforClick(window);
		}
		else
		{
			//draw nothing
		}
	}
	if (col_1_added == true)
	{
		if (col_1_count == 1)
		{
			//second column of first pointbox;
			pointbox1->draw(window);
			pointbox1->listenforClick(window);
		}
		if (col_1_count == 2)
		{
			pointbox1->draw(window);
			pointbox1->listenforClick(window);
			pointbox2->draw(window);
			pointbox2->listenforClick(window);
		}
		if (col_1_count == 3)
		{
			pointbox1->draw(window);
			pointbox1->listenforClick(window);
			pointbox2->draw(window);
			pointbox2->listenforClick(window);
			pointbox3->draw(window);
			pointbox3->listenforClick(window);
		}
		if (col_1_count == 4 || col_1_count > 4)
		{
			pointbox1->draw(window);
			pointbox1->listenforClick(window);
			pointbox2->draw(window);
			pointbox2->listenforClick(window);
			pointbox3->draw(window);
			pointbox3->listenforClick(window);
			pointbox4->draw(window);
			pointbox4->listenforClick(window);
		}
		else
		{
			//draw nothing
		}
	}

	if (col_2_added == true)
	{
		if (col_2_count == 1)
		{
			//second column of first pointbox;
			pointbox6->draw(window);
			pointbox6->listenforClick(window);
		}
		if (col_2_count == 2)
		{
			pointbox6->draw(window);
			pointbox6->listenforClick(window);
			pointbox7->draw(window);
			pointbox7->listenforClick(window);
		}
		if (col_2_count == 3)
		{
			pointbox6->draw(window);
			pointbox6->listenforClick(window);
			pointbox7->draw(window);
			pointbox7->listenforClick(window);
			pointbox8->draw(window);
			pointbox8->listenforClick(window);
		}
		if (col_2_count == 4 || col_2_count > 4)
		{
			pointbox6->draw(window);
			pointbox6->listenforClick(window);
			pointbox7->draw(window);
			pointbox7->listenforClick(window);
			pointbox8->draw(window);
			pointbox8->listenforClick(window);
			pointbox9->draw(window);
			pointbox9->listenforClick(window);
		}
		else
		{
			//draw nothing
		}
	}

	if (col_3_added == true)
	{
		if (col_3_count == 1)
		{
			//second column of first pointbox;

			pointbox11->draw(window);
			pointbox11->listenforClick(window);
		}
		if (col_3_count == 2)
		{
			pointbox11->draw(window);
			pointbox11->listenforClick(window);
			pointbox12->draw(window);
			pointbox12->listenforClick(window);
		}
		if (col_3_count == 3)
		{
			pointbox11->draw(window);
			pointbox11->listenforClick(window);
			pointbox12->draw(window);
			pointbox12->listenforClick(window);
			pointbox13->draw(window);
			pointbox13->listenforClick(window);
		}
		if (col_3_count == 4 || col_3_count > 4)
		{
			pointbox11->draw(window);
			pointbox11->listenforClick(window);
			pointbox12->draw(window);
			pointbox12->listenforClick(window);
			pointbox13->draw(window);
			pointbox13->listenforClick(window);
			pointbox14->draw(window);
			pointbox14->listenforClick(window);
		}
		else
		{
			//draw nothing
		}
	}

	if (col_4_added == true)
	{
		if (col_4_count == 1)
		{
			//second column of first pointbox;
			pointbox16->draw(window);
			pointbox16->listenforClick(window);
		}
		if (col_4_count == 2)
		{

			pointbox16->draw(window);
			pointbox16->listenforClick(window);
			pointbox17->draw(window);
			pointbox17->listenforClick(window);
		}
		if (col_4_count == 3)
		{
			pointbox16->draw(window);
			pointbox16->listenforClick(window);
			pointbox17->draw(window);
			pointbox17->listenforClick(window);
			pointbox18->draw(window);
			pointbox18->listenforClick(window);
		}
		if (col_4_count == 4 || col_4_count > 4)
		{
			pointbox16->draw(window);
			pointbox16->listenforClick(window);
			pointbox17->draw(window);
			pointbox17->listenforClick(window);
			pointbox18->draw(window);
			pointbox18->listenforClick(window);
			pointbox19->draw(window);
			pointbox19->listenforClick(window);
		}
		else
		{
			//draw nothing
		}
	}

	window.draw(add_button.Sprite);
	window.draw(add_button.Label);
	window.draw(add_col_1.Sprite);
	window.draw(add_col_1.Label);
	window.draw(point_plot_1.Sprite);
	window.draw(point_plot_1.Label);

	window.draw(*degree_entry);
	
}

Gui::~Gui()
{
	//perhaps we should make a vector of this
	delete tb1;
	delete tb2;
	delete tb3;
	delete tb4;

	//perhaps we should make a vector of this
	delete pointbox0;
	delete pointbox1;
	delete pointbox2;
	delete pointbox3;
	delete pointbox4;
	delete pointbox5;
	delete pointbox6;
	delete pointbox7;
	delete pointbox8;
	delete pointbox9;
	delete pointbox10;
	delete pointbox11;
	delete pointbox12;
	delete pointbox13;
	delete pointbox14;
	delete pointbox15;
	delete pointbox16;
	delete pointbox17;
	delete pointbox18;
	delete pointbox19;

	delete degree_entry;

}
