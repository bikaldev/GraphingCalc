
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum class Type
{
	Number,
	Letter,
	AlphaNumeric,
	Email,
	IP,
	Any
};

class Textbox : public sf::Transformable, public sf::Drawable
{
private:
	sf::Vector2f t_position;
	sf::Vector2f t_size;
	sf::Color t_text_color;
	sf::Color t_background_color;
	unsigned int t_character_size;
	bool t_has_focus;
	Type t_type;
	unsigned int t_border_width;
	unsigned int t_limit;

	std::string t_string;
	sf::Font t_font;
	mutable int cursor_iteration_count;
	unsigned int t_cursor_position;
	sf::RectangleShape t_box;
	mutable sf::Text t_text;
	sf::Color t_border_color;

private:
	virtual void
	draw(sf::RenderTarget& target,
		sf::RenderStates states = sf::RenderStates::Default) const override;

public:
	Textbox();
	Textbox(sf::Vector2f size, sf::Vector2f position, std::string path,
		Type type = Type::Any);
	//the copy constructors were deleted i am removing the deletion of the copy constructors
	//Textbox(Textbox &) = delete;
	//Textbox operator=(Textbox &) = delete;
	//Textbox(Textbox &&) = delete;
	//Textbox operator=(Textbox &&) = delete;

	unsigned int getCharacterSize() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
	std::string getString() const;
	unsigned int getStringLength() const;

	void setFocus(bool focus);
	void setType(Type type);
	void setPosition(sf::Vector2f position);
	void setPosition(float x, float y);
	void setSize(sf::Vector2f size);
	void setSize(float width, float height);
	void setCharacterSize(unsigned int character_size);
	void setTextColor(sf::Color text_color);
	void setBorderColor(sf::Color);
	void setBackgroundColor(sf::Color background_color);
	void setBorderSize(unsigned int size);
	void setLimit(unsigned int limit);
	void setFont(std::string path);
	void listenForText(sf::Event& event);
	void listenForClick(sf::RenderWindow& window);
};
