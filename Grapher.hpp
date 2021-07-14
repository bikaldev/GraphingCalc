#include <SFML/Graphics.hpp>
#define MARGIN_RATIO 0.1;
#define GRID_RATIO 0.1;
#define DRAG_SMOOTHNESS 0.026667;

class Grapher
{
private:
	sf::Vector2f origin;
	sf::Vector2f margin;
	float size;
	sf::Vector2f offset;
	float grid_spacing;

public:
	Grapher(float size, sf::Vector2f init_offset);
	~Grapher() {

	};

	void drawLayout(sf::RenderWindow& window, bool isGridOn = false);
	void update(sf::Vector2f);
	void reset();

private:
	void drawAxes(sf::RenderWindow& window);
	void drawGrid(sf::RenderWindow& window);
	void drawBackground(sf::RenderWindow& window);
};

Grapher::Grapher(float size, sf::Vector2f init_offset)
{
	this->size = size;
	this->offset = init_offset;
	this->grid_spacing = size * GRID_RATIO;
	margin.x = size * MARGIN_RATIO;
	margin.y = size * MARGIN_RATIO;
	origin.x = margin.x;
	origin.y = size / 2.0f;
	this->origin += this->offset;
}

void Grapher::update(sf::Vector2f mouse_offset)
{
	mouse_offset.x *= DRAG_SMOOTHNESS;
	mouse_offset.y *= DRAG_SMOOTHNESS;
	this->origin += mouse_offset;
}

void Grapher::reset()
{
	origin.x = margin.x;
	origin.y = size / 2.0f;
	this->origin += this->offset;
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
		sf::RectangleShape x_axis(sf::Vector2f(size, 2));
		x_axis.setPosition(sf::Vector2f(this->offset.x, origin.y));
		x_axis.setFillColor(sf::Color::Black);
		window.draw(x_axis);
	}
}

void Grapher::drawGrid(sf::RenderWindow& window)
{
	float grid_offset = this->grid_spacing;
	while (grid_offset < (size + this->offset.x - origin.x))
	{
		sf::RectangleShape grid(sf::Vector2f(1, size));
		grid.setFillColor(sf::Color(150, 150, 150));
		grid.setPosition(origin.x + grid_offset, this->offset.y);
		window.draw(grid);
		grid_offset += this->grid_spacing;
	}

	grid_offset = -this->grid_spacing;
	while (grid_offset > (this->offset.x - origin.x))
	{
		sf::RectangleShape grid(sf::Vector2f(1, size));
		grid.setFillColor(sf::Color(150, 150, 150));
		grid.setPosition(origin.x + grid_offset, this->offset.y);
		window.draw(grid);
		grid_offset -= this->grid_spacing;
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