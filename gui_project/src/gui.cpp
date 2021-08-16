#include "gui.hpp"

void Gui::init()
{
	//these are for buttons
	tb1 = new Textbox(sf::Vector2f{tb_w, tb_h}, sf::Vector2f{sp_x, sp_y},"assets/arial.ttf");
	tb2 = new Textbox(sf::Vector2f{tb_w, tb_h}, sf::Vector2f{sp_x, sp_y+tb_h+40.f},"assets/arial.ttf");
	tb3 = new Textbox (sf::Vector2f{tb_w, tb_h}, sf::Vector2f{sp_x, sp_y+tb_h*2+40.f*2},"assets/arial.ttf");
	tb4 = new Textbox (sf::Vector2f{tb_w, tb_h}, sf::Vector2f{sp_x, sp_y+tb_h*3+40.f*3},"assets/arial.ttf");
    window.create(sf::VideoMode(1280, 720), "Graph Layout", sf::Style::Default);
    //graph(600.0f, sf::Vector2f(0.0f, 0.0f));
    //for equations
    eqns.setLabel("Equations");
	eqns.Create();
	eqns.setPosition(eq_pos.x, eq_pos.y);
    //for points
    ptns.setLabel("Points");
	ptns.Create();
	ptns.setPosition(eq_pos.x+eqns.width()+25.f, eq_pos.y);
    //for adding
    add.setLabel("Add");
	add.Create();
	add.setPosition(add_pos.x, add_pos.y);
    //first eqn plotter
    
    btn1.setLabel("Plot"); 
	btn1.Create();
	btn1.setPosition(sp_x+tb_w+25.f , sp_y);
    //second eqn plotter
    
    btn2.setLabel("Plot"); 
	btn2.Create();
	btn2.setPosition(sp_x+tb_w+25.f , sp_y+tb_h+40.f);
    //third eqn plotter
    
    btn3.setLabel("Plot"); 
	btn3.Create();
	btn3.setPosition( sp_x+tb_w+25.f, sp_y+tb_h*2+40.f*2);
    //fourth eqn plotter
    //Textbox tb4(sf::Vector2f{tb_w, tb_h}, sf::Vector2f{sp_x, sp_y+tb_h*3+40.f*3},"assets/arial.ttf");
	btn4.setLabel("Plot"); 
	btn4.Create();
	btn4.setPosition(sp_x+tb_w+25.f, sp_y+tb_h*3+40.f*3);


	//now we create pointboxes
	//four different pointboxes need to be created


}


void Gui::main()
{
	
	while (window.isOpen())
	{

		window.clear();
		//graph.drawLayout(window, true);
		//graph.draw(window);
		//graph.listenToStaticEvents(window);
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			tb1->listenForText(evnt);
			tb2->listenForText(evnt);
			tb3->listenForText(evnt);
			tb4->listenForText(evnt);
			//graph.listenToLazyEvent(evnt, window);
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
		if (eqn_clicked == true | ptn_clicked == true)
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
			//graph.addCurve(tb1.getString());
		}
		if (btn2.clicked == true)
		{
			//here if edited the previous plot remains as well this needs to be taken care of
			//graph.addCurve(tb2.getString());
		}
		if (btn3.clicked == true)
		{
			//here if edited the previous plot remains as well this needs to be taken care of
			//graph.addCurve(tb3.getString());
		}
		if (btn4.clicked == true)
		{
			//here if edited the previous plot remains as well this needs to be taken care of
			//graph.addCurve(tb4.getString());
		}

		if (add.clicked == true)
		{
			total_click++;
			add_clicked = true;
		}		
		//this code just undrawed an already drawn button.
		//this is the exact code to implement switching.
		//we might encounter one problem here.
		if (add_clicked== true)
		{
		
			if (total_click == 1)
			{
	
				window.draw(*tb2);
				window.draw(btn2.Sprite);
				window.draw(btn2.Label);
				btn2.listen(window);
				tb2->listenForClick(window);
			}
			if (total_click == 2)
			{
				window.draw(*tb3);
				window.draw(btn3.Sprite);
				window.draw(btn3.Label);
				btn3.listen(window);
				tb3->listenForClick(window);

			}
			if(total_click == 3 )
			{
				
				window.draw(*tb4);
				window.draw(btn4.Sprite);
				window.draw(btn4.Label);
				btn4.listen(window);
				tb4->listenForClick(window);
			}
			if (total_click > 3)
			{
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
	add_col_1.setLabel("Add Points");
	add_col_1.Create();
	add_col_1.setPosition(300.f,100.f);

	point_plot_1.setLabel("Points");
	point_plot_1.Create();
	point_plot_1.setPosition(300.f,150.f);

	add_col_2.setLabel("Add Points");
	add_col_2.Create();
	add_col_2.setPosition(300.f,200.f);

	point_plot_2.setLabel("Points");
	point_plot_2.Create();
	point_plot_2.setPosition(300.f,250.f);

	add_col_3.setLabel("Add Points");
	add_col_3.Create();
	add_col_3.setPosition(300.f,300.f);

	point_plot_3.setLabel("Points");
	point_plot_3.Create();
	point_plot_3.setPosition(300.f,350.f);

	add_col_4.setLabel("Add Points");
	add_col_4.Create();
	add_col_4.setPosition(300.f,400.f);
	
	point_plot_4.setLabel("Points");
	point_plot_4.Create();
	point_plot_4.setPosition(300.f,450.f);

	

	add_button.setLabel("Add");
	add_button.Create();
	add_button.setPosition(50.f,600.f);

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
	
	pointbox0 = new Column(sf::Vector2f{150.f, 50.f}, "assets/arial.ttf");
	pointbox0->draw(window);
	

	if (pointbox_added == true)
	{
		if (pointbox_count == 1)
		{
			//first element of the second pointbox
			pointbox5 = new Column(sf::Vector2f{150.f, 110.f}, "assets/arial.ttf");
			pointbox5->draw(window);
		}

		if (pointbox_count == 2)
		{
			pointbox10 = new Column(sf::Vector2f{150.f, 170.f}, "assets/arial.ttf");
			pointbox10->draw(window);
		}

		if (pointbox_count == 3)
		{
			pointbox15 = new Column(sf::Vector2f{150.f,230.f}, "assets/arial.ttf");
			pointbox15->draw(window);
		}

		if (pointbox_count > 3)
		{
			//draw nothing
		}
		
	}
	if (col_1_added == true)
	{
		if (col_1_count == 1)
		{
			//second column of first pointbox;
			pointbox1 = new Column(sf::Vector2f{210.f, 50.f}, "assets/arial.ttf");
			pointbox1->draw(window);
		}
		if (col_1_count == 2)
		{
			pointbox2 = new Column(sf::Vector2f{270.f, 50.f}, "assets/arial.ttf");
			pointbox2->draw(window);
		}
		if (col_1_count == 3)
		{
			pointbox3 = new Column(sf::Vector2f{330.f, 50.f}, "assets/arial.ttf");
			pointbox3->draw(window);
		}
		if (col_1_count == 4)
		{
			pointbox4 = new Column(sf::Vector2f{390.f, 50.f}, "assets/arial.ttf");
			pointbox4->draw(window);
		}
		if (col_1_count > 4)
		{
			//draw nothing
		}
		
	}

	if (col_2_added == true)
	{
		if (col_2_count == 1)
		{
			//second column of first pointbox;
			pointbox6 = new Column(sf::Vector2f{210.f, 110.f}, "assets/arial.ttf");
			pointbox6->draw(window);
		}
		if (col_2_count == 2)
		{
			pointbox7 = new Column(sf::Vector2f{270.f, 110.f}, "assets/arial.ttf");
			pointbox7->draw(window);
		}
		if (col_2_count == 3)
		{
			pointbox8 = new Column(sf::Vector2f{330.f, 110.f}, "assets/arial.ttf");
			pointbox8->draw(window);
		}
		if (col_2_count == 4)
		{
			pointbox9 = new Column(sf::Vector2f{390.f, 110.f}, "assets/arial.ttf");
			pointbox9->draw(window);
		}
		if (col_2_count > 4)
		{
			//draw nothing
		}
		
	}

	if (col_3_added == true)
	{
		if (col_3_count == 1)
		{
			//second column of first pointbox;
			pointbox11 = new Column(sf::Vector2f{2100.f, 170.f}, "assets/arial.ttf");
			pointbox11->draw(window);
		}
		if (col_3_count == 2)
		{
			pointbox12 = new Column(sf::Vector2f{270.f, 170.f}, "assets/arial.ttf");
			pointbox12->draw(window);
		}
		if (col_3_count == 3)
		{
			pointbox13 = new Column(sf::Vector2f{330.f, 170.f}, "assets/arial.ttf");
			pointbox13->draw(window);
		}
		if (col_3_count == 4)
		{
			pointbox14 = new Column(sf::Vector2f{390.f, 170.f}, "assets/arial.ttf");
			pointbox14->draw(window);
		}
		if (col_3_count > 4)
		{
			//draw nothing
		}
		
	}

	if (col_4_added == true)
	{
		if (col_4_count == 1)
		{
			//second column of first pointbox;
			pointbox16 = new Column(sf::Vector2f{210.f, 230.f}, "assets/arial.ttf");
			pointbox16->draw(window);
		}
		if (col_4_count == 2)
		{
			pointbox17 = new Column(sf::Vector2f{270.f, 230.f}, "assets/arial.ttf");
			pointbox17->draw(window);
		}
		if (col_4_count == 3)
		{
			pointbox18 = new Column(sf::Vector2f{330.f, 230.f}, "assets/arial.ttf");
			pointbox18->draw(window);
		}
		if (col_4_count == 4)
		{
			pointbox19 = new Column(sf::Vector2f{390.f, 230.f}, "assets/arial.ttf");
			pointbox19->draw(window);
		}
		if (col_4_count > 4)
		{
			//draw nothing
		}
		
	}
	
	

	

	window.draw(add_button.Sprite);
	window.draw(add_button.Label);
	
	window.draw(add_col_1.Sprite);
	window.draw(add_col_1.Label);
	window.draw(add_col_2.Sprite);
	window.draw(add_col_2.Label);
	window.draw(add_col_3.Sprite);
	window.draw(add_col_3.Label);
	window.draw(add_col_4.Sprite);
	window.draw(add_col_4.Label);

	window.draw(point_plot_1.Sprite);
	window.draw(point_plot_1.Label);
	window.draw(point_plot_2.Sprite);
	window.draw(point_plot_2.Label);
	window.draw(point_plot_3.Sprite);
	window.draw(point_plot_3.Label);
	window.draw(point_plot_4.Sprite);
	window.draw(point_plot_4.Label);


			
			
}
