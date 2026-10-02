#include "CheckBox.h"

CheckBox::CheckBox(sf::Shape* _shape)
{
    this->shape = _shape;
    isActive = false;
    isOver = false;
    shape->setOutlineColor(sf::Color(100, 100, 100));
    shape->setOutlineThickness(5.f);
}
void CheckBox::Update()
{
    sf::Color fillC = isActive ? COLOR_G : COLOR_R;

    this->shape->setFillColor(isOver ? fillC + sf::Color(20, 20, 20) : fillC);

    //isActive = false;
}

void CheckBox::Draw(sf::RenderTarget& _render)
{
    _render.draw(*shape);
}

void CheckBox::MoosePos(const sf::Vector2i& const _pos)
{
    //std::cout << "get mouse" << std::endl;
    CheckCollision(_pos);
}

void CheckBox::Released()
{
}

void CheckBox::Pressed()
{
    if (isOver)
    {
        isActive = !isActive;
    }
}

bool CheckBox::IsActive()
{
    return isActive;
}

bool CheckBox::IsOver()
{
    return isOver;
}

void CheckBox::CheckCollision(const sf::Vector2i& const _pos)
{
    sf::FloatRect floatR = this->shape->getGlobalBounds();
    sf::Vector2f vec = sf::Vector2f(_pos);
    isOver = CollisionRectPoint(floatR, vec);
    //std::cout << "x : " << vec.x << "y : " << vec.y << std::endl;
    //std::cout << (isOver ? "collision" : "No collision") << std::endl;
}
