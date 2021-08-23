#pragma once
#include "CurveDrawer.hpp"
#include "ImplicitPlotter.hpp"
#include "PointPlot.hpp"
#include "stringEvaluator.hpp"
#include "windowsize.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>
#define MARGIN_RATIO 0.1
#define GRID_SIZE 25
#define DRAG_SMOOTHNESS 0.03
#define COLOR_MAX 255
#define SEED 20

enum Zoom
{
	in,
	out
};

class Grapher
{
private:
	sf::Vector2f origin;
	sf::Vector2f margin;
	float size;
	sf::Vector2f offset;
	float grid_spacing;
	float amplitude;
	PointPlot pointPlotter;
	std::vector<CurveInfo> curves;

public:
	Grapher() = default;
	Grapher(float size, sf::Vector2f init_offset);
	~Grapher() {};

	void drawLayout(sf::RenderWindow& window, bool isGridOn = false);
	void listenToLazyEvent(sf::Event& evnt, sf::RenderWindow& window);
	void listenToStaticEvents(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	virtual void addCurve(std::string s, textboxId id);
	void operator()(float, sf::Vector2f);

private:
	void drawAxes(sf::RenderWindow& window);
	void drawGrid(sf::RenderWindow& window);
	void drawBackground(sf::RenderWindow& window);
	void drawYDepCurve(CurveInfo info, sf::RenderWindow& window);
	void drawXDepCurve(CurveInfo info, sf::RenderWindow& window);
	void drawImplicitCurve(CurveInfo info, sf::RenderWindow& window);
	void zoomInandOut(Zoom z_type, float factor = 1.5f);
	void update(sf::Vector2f);
	void setParams();
	void setPointPlotterParams();
	void reset();
	void markPoints(sf::RenderWindow& window);

private:
	//inline
	int randomRGB()
	{
		return rand() % 255;
	}
};