#include "button.hpp"
#include "textbox.hpp"

class Column
{
    private:
        Textbox *x;
        Textbox *y;
        sf::Vector2f sp_1;
        sf::Vector2f size{50.f, 30.f};
        sf::Vector2f sp_2;
        std::string path;
    public:
        Column(){}
        Column(sf::Vector2f a, std::string c):sp_1(a), path(c) {
            sp_2 = {sp_1.x, sp_1.y+size.y+15.f};
            x = new Textbox(size, sp_1, "assets/arial.ttf", Type::Any);
            y = new Textbox(size, sp_2, "assets/arial.ttf", Type::Any);
        }
        void draw(sf::RenderWindow& window);
        void listenforClick(sf::RenderWindow &window);
        void listenforText(sf::Event &event);
        //perhaps we can add two new value here.
        void getstring();
        
};
