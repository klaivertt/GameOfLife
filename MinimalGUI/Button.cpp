#include "Button.h"

Button::Button(sf::Shape* _shape)
{
    this->shape = _shape;
    isActive = false;
    isOver = false;
}
void Button::Update()
{
    sf::Color fillC = isActive ? COLOR_G : COLOR_R;

    this->shape->setFillColor(isOver ? fillC + sf::Color(20,20,20) : fillC);
}

void Button::Draw(sf::RenderTarget& _render)
{
    _render.draw(*shape);
}

void Button::MoosePos(const sf::Vector2i& const _pos)
{
    //std::cout << "get mouse" << std::endl;
    CheckCollision(_pos);
}

void Button::Pressed()
{
    if (isOver)
    {
        isActive = true;
    }
}
void Button::Released()
{
    if (isOver)
    {
        isActive = false;
    }
}

bool Button::IsActive()
{
    return isActive;
}

bool Button::IsOver()
{
    return isOver;
}

void Button::CheckCollision(const sf::Vector2i& const _pos)
{
    sf::FloatRect floatR = this->shape->getGlobalBounds();
    sf::Vector2f vec = sf::Vector2f(_pos);
    isOver = CollisionRectPoint(floatR, vec);
    //std::cout << "x : " << vec.x << "y : " << vec.y << std::endl;
    //std::cout << (isOver ? "collision" : "No collision") << std::endl;
}
