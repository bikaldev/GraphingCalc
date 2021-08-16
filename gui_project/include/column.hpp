#include "button.hpp"
#include "textbox.hpp"

class Column
{
    private:
        Textbox *x;
        Textbox *y;
        sf::Vector2f sp_1;
        sf::Vector2f size{50.f, 30.f};
        sf::Vector2f sp_2{sp_1.x, sp_1.y+size.x+15.f};
        std::string path;
    public:
        Column(){}
        Column(sf::Vector2f a, std::string c):sp_1(a), path(c) {}
        void draw(sf::RenderWindow& window);
        
};
