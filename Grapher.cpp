#include "Grapher.hpp"

Grapher::Grapher(sf::Vector2f size, sf::Vector2f init_offset)
{
	this->size = size.x;
	this->offset = init_offset;
	this->amplitude = 19.0f;
	margin.x = size.x * MARGIN_RATIO_X;
	margin.y = size.y * MARGIN_RATIO_Y;
	srand(SEED);
	setParams();
}

void Grapher::operator()(sf::Vector2f size, sf::Vector2f init_offset)
{
	this->size = size.x;
	this->offset = init_offset;
	this->amplitude = 19.0f;
	margin.x = size.x * MARGIN_RATIO_X;
	margin.y = size.y * MARGIN_RATIO_Y;
	srand(SEED);
	setParams();
}

void Grapher::update(sf::Vector2f mouse_offset)
{
	mouse_offset.x *= DRAG_SMOOTHNESS;
	mouse_offset.y *= DRAG_SMOOTHNESS;
	this->origin += mouse_offset;
	this->pointPlotter.setOrigin(this->origin);
}

void Grapher::reset()
{
	origin.x = margin.x;
	origin.y = size / 2.0f;
	this->origin += this->offset;
	this->pointPlotter.setOrigin(origin);
}

void Grapher::setPointPlotterParams()
{
	this->pointPlotter.setOffset(offset);
	this->pointPlotter.setOrigin(origin);
	this->pointPlotter.setSize(size);
	this->pointPlotter.setAmplitude(this->amplitude);
}

void Grapher::setParams()
{
	this->grid_spacing = GRID_SIZE;
	origin.x = margin.x;
	origin.y = margin.y;
	this->origin += this->offset;
	setPointPlotterParams();
}

void Grapher::addCurve(std::string s, textboxId id)
{
	if (s.length() <= 0)
	{
		return;
	}
	try
	{
		CurveInfo info = StringEvaluator::evaluate(s);
		for (int i = 0; i < static_cast<int>(curves.size()); i++)
		{
			//a seg fault has occured in this line of code
			if (curves[i].id == id)
			{
				curves[i].equation = info.equation;
				curves[i].type = info.type;
				return;
			}

			//if this is kept it-1 then we get another error so it can't be the answer.
		}
		info.id = id;
		info.color = sf::Color(randomRGB(), randomRGB(), randomRGB());
		curves.push_back(info);
	}
	catch (FORMATERROR e)
	{
		std::cerr << e.message() << std::endl;
		throw;
	}
}

void Grapher::deleteCurve(textboxId id)
{
	for (int i = 0; i < static_cast<int>(curves.size()); i++)
	{
		if (curves[i].id == id)
		{
			curves[i].equation = "";
			curves[i].type = None;
			return;
		}
	}
}

void Grapher::draw(sf::RenderWindow& window)
{
	try
	{
		CurveInfo info;
		for (int i = 0; i < static_cast<int>(curves.size()); i++)
		{

			info = curves[i];
			switch (info.type)
			{
				case X_dep:
					drawXDepCurve(info, window);
					break;
				case Y_dep:
					drawYDepCurve(info, window);
					break;
				case Implicit:
					drawImplicitCurve(info, window);
					break;
				case None:
					//throw error
					break;
				default:
					break;
			}
		}
	}
	catch (INVALIDOPERAND e)
	{
		std::cout << "Error at Grapher/draw: " << e.get_message() << std::endl;
		throw;
	}
	catch (INVALIDFORMAT e)
	{
		std::cout << "Error at Grapher/draw" << e.get_message() << std::endl;
		throw;
	}
}

void Grapher::zoomInandOut(Zoom z_type, float factor)
{
	if (z_type == Zoom::out)
	{
		factor = 1.0f / factor;
	}

	this->amplitude *= factor;
	this->grid_spacing *= factor;
	this->origin.x += (this->origin.x - (size / 2)) * -factor;
}

void Grapher::zoomIn()
{
	zoomInandOut(Zoom::in);
}

void Grapher::zoomOut()
{
	zoomInandOut(Zoom::out);
}

void Grapher::drawBackground(sf::RenderWindow& window)
{
	sf::RectangleShape Background(sf::Vector2f(size, size));
	Background.setFillColor(sf::Color::White);
	Background.setPosition(this->offset);

	window.draw(Background);
}

void Grapher::drawAxes(sf::RenderWindow& window)
{
	if (this->origin.x <= this->offset.x + this->size && this->origin.x >= this->offset.x)
	{
		sf::RectangleShape y_axis(sf::Vector2f(2, size));
		y_axis.setPosition(sf::Vector2f(origin.x, this->offset.y));
		y_axis.setFillColor(sf::Color::Black);
		window.draw(y_axis);
	}
	if (this->origin.y <= this->offset.y + size && this->origin.y >= this->offset.y)
	{
		sf::RectangleShape x_axis(sf::Vector2f(size, 2.5));
		x_axis.setPosition(sf::Vector2f(this->offset.x, origin.y));
		x_axis.setFillColor(sf::Color::Black);
		window.draw(x_axis);
	}
}

void Grapher::drawGrid(sf::RenderWindow& window)
{
	// float aspectRatio = static_cast<float>(window.getSize().y) / window.getSize().x;
	float aspectRatio = 1;
	float grid_offset = this->grid_spacing * aspectRatio;
	while (grid_offset < (size + this->offset.x - origin.x))
	{
		sf::RectangleShape grid(sf::Vector2f(1, size));
		grid.setFillColor(sf::Color(150, 150, 150));
		grid.setPosition(origin.x + grid_offset, this->offset.y);
		window.draw(grid);
		grid_offset += this->grid_spacing * aspectRatio;
	}

	grid_offset = -this->grid_spacing * aspectRatio;
	while (grid_offset > (this->offset.x - origin.x))
	{
		sf::RectangleShape grid(sf::Vector2f(1, size));
		grid.setFillColor(sf::Color(150, 150, 150));
		grid.setPosition(origin.x + grid_offset, this->offset.y);
		window.draw(grid);
		grid_offset -= this->grid_spacing * aspectRatio;
	}

	grid_offset = this->grid_spacing;
	while (grid_offset < (size + this->offset.y - origin.y))
	{
		sf::RectangleShape grid(sf::Vector2f(size, 1));
		grid.setFillColor(sf::Color(150, 150, 150));
		grid.setPosition(this->offset.x, origin.y + grid_offset);
		window.draw(grid);
		grid_offset += this->grid_spacing;
	}

	grid_offset = -this->grid_spacing;
	while (grid_offset > (this->offset.y - origin.y))
	{
		sf::RectangleShape grid(sf::Vector2f(size, 1));
		grid.setFillColor(sf::Color(150, 150, 150));
		grid.setPosition(this->offset.x, origin.y + grid_offset);
		window.draw(grid);
		grid_offset -= this->grid_spacing;
	}
}

void Grapher::drawLayout(sf::RenderWindow& window, bool isGridOn)
{

	drawBackground(window);
	drawAxes(window);

	if (isGridOn)
	{
		this->drawGrid(window);
	}
}

void Grapher::drawYDepCurve(CurveInfo info, sf::RenderWindow& window)
{
	try
	{
		CurveDrawer(this->origin, this->offset, size, this->amplitude, info.color).drawYDep(info.equation, window);
	}
	catch (INVALIDOPERAND e)
	{
		std::cout << "Error at Grapher/drawYdep: " << e.get_message() << std::endl;
		throw;
	}
	catch (INVALIDFORMAT e)
	{
		std::cout << "Error at Grapher/drawYdep" << e.get_message() << std::endl;
		throw;
	}
}

void Grapher::drawXDepCurve(CurveInfo info, sf::RenderWindow& window)
{
	try
	{
		CurveDrawer(this->origin, this->offset, size, this->amplitude, info.color).drawXDep(info.equation, window);
	}
	catch (INVALIDOPERAND e)
	{
		std::cout << "Error at Grapher/drawXdep: " << e.get_message() << std::endl;
		throw;
	}
	catch (INVALIDFORMAT e)
	{
		std::cout << "Error at Grapher/drawXDep" << e.get_message() << std::endl;
		throw;
	}
}

void Grapher::drawImplicitCurve(CurveInfo info, sf::RenderWindow& window)
{
	WindowSize DefaultWindow;
	DefaultWindow.ActualRange = Points((offset.x - origin.x) / amplitude, (offset.x + size - origin.x) / amplitude);
	DefaultWindow.MagnifiedRange = Points(offset.x - origin.x, offset.x + size - origin.x);
	DefaultWindow.plane.width = size;
	DefaultWindow.plane.height = size;
	DefaultWindow.plane.top = origin.y;
	DefaultWindow.plane.left = origin.x;
	try
	{
		ImplicitPlotter(DefaultWindow, origin, info.color).display(info.equation, window);
	}
	catch (INVALIDOPERAND e)
	{
		std::cout << "Error at Grapher/drawImplicit: " << e.get_message() << std::endl;
		throw;
	}
	catch (INVALIDFORMAT e)
	{
		std::cout << "Error at Grapher/drawImplicit" << e.get_message() << std::endl;
		throw;
	}
}

void Grapher::listenToLazyEvent(sf::Event& evnt, sf::RenderWindow& window)
{

	static bool isMousePressed = false;
	static sf::Vector2i init_position;
	if (evnt.type == evnt.MouseButtonPressed)
	{
		init_position = sf::Mouse::getPosition(window);
		if (init_position.x >= offset.x && init_position.x <= offset.x + size && init_position.y >= offset.y && init_position.y <= offset.y + size)
		{
			isMousePressed = true;
		}
	}

	if (evnt.type == evnt.MouseMoved && isMousePressed)
	{
		sf::Vector2i final_position = sf::Mouse::getPosition(window);
		update(static_cast<sf::Vector2f>(static_cast<sf::Vector2f>(final_position - init_position)));
	}
	if (evnt.type == evnt.MouseButtonReleased)
	{
		isMousePressed = false;
	}
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	// {
	// 	reset();
	// }
	if (evnt.type == sf::Event::Resized)
	{
		float width = static_cast<float>(window.getSize().x);
		this->size = width;
		setParams();
	}
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	// {
	// 	zoomInandOut(Zoom::in);
	// 	setPointPlotterParams();
	// }
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	// {
	// 	zoomInandOut(Zoom::out);
	// 	setPointPlotterParams();
	// }
	// this->pointPlotter.takeInput(evnt, window);
}

void Grapher::markPoints(sf::RenderWindow& window)
{
	this->pointPlotter.markPoints(window);
}

void Grapher::fitPoints(int deg)
{
	this->pointPlotter.setDegree(deg);
	this->pointPlotter.fitCurve();
}

void Grapher::clearPoints()
{
	this->pointPlotter.clear();
}

void Grapher::listenToStaticEvents(sf::RenderWindow& window)
{
	// Curve Drawing logic

	//Point plotting logic
	markPoints(window);
	this->pointPlotter.listenToStaticEvent(window);
}

void Grapher::takePoint(double x, double y)
{
	this->pointPlotter.takePoint(x, y);
}