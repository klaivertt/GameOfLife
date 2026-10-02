#include "Load.h"
#include "GameData.h"
#include "Button.h"
#include "CheckBox.h"
int Load(GameData& _data)
{
    sf::Font& font = _data.font;
    if (!font.loadFromFile("arial.ttf"))
    {
        return -1;
    }
    sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
    shape->setPosition(sf::Vector2f(40.f, 40.f));
    _data.widget.push_back(new Button(shape));

    shape = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
    shape->setPosition(sf::Vector2f(40.f, 90.f));
    _data.widget.push_back(new CheckBox(shape));

    sf::CircleShape* circle = new sf::CircleShape(20.f);
    circle->setPosition(sf::Vector2f(120.f, 40.f));
    _data.widget.push_back(new Button(circle));

    circle = new sf::CircleShape(20.f);
    circle->setPosition(sf::Vector2f(1200.f, 40.f));
    _data.widget.push_back(new CheckBox(circle));

    circle = new sf::CircleShape(20.f);
    circle->setPosition(sf::Vector2f(180.f, 40.f));
    _data.widget.push_back(new Button(circle));
    return 0;
}