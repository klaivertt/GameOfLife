#include "Button.h"

Button::Button(sf::Shape* _shape)
{
    this->m_shape = _shape;
    m_isActive = false;
    m_isOver = false;
}

Button::~Button()
{
    delete this->m_shape;
}

void Button::Update()
{
    sf::Color fillC = m_isActive ? COLOR_G : COLOR_R;

    this->m_shape->setFillColor(m_isOver ? fillC + sf::Color(20,20,20) : fillC);
}

void Button::Draw(sf::RenderTarget& _render)
{
    _render.draw(*m_shape);
}

void Button::MoosePos(const sf::Vector2i& const _pos)
{
    //std::cout << "get mouse" << std::endl;
    CheckCollision(_pos);
}

void Button::Pressed()
{
    if (m_isOver)
    {
        m_isActive = true;
    }
}
void Button::Released()
{
    if (m_isOver)
    {
        m_isActive = false;
    }
}

bool Button::IsActive()
{
    return m_isActive;
}

bool Button::IsOver()
{
    return m_isOver;
}

void Button::CheckCollision(const sf::Vector2i& const _pos)
{
    sf::FloatRect floatR = this->m_shape->getGlobalBounds();
    sf::Vector2f vec = sf::Vector2f(_pos);
    m_isOver = CollisionRectPoint(floatR, vec);
    //std::cout << "x : " << vec.x << "y : " << vec.y << std::endl;
    //std::cout << (isOver ? "collision" : "No collision") << std::endl;
}
