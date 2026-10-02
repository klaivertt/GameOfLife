#include "CheckBox.h"

CheckBox::CheckBox(sf::Shape* _shape)
{
    this->m_shape = _shape;
    m_isActive = false;
    m_isOver = false;
    m_shape->setOutlineColor(sf::Color(100, 100, 100));
    m_shape->setOutlineThickness(5.f);
}

CheckBox::~CheckBox()
{
    delete this->m_shape;
}

void CheckBox::Update()
{
    sf::Color fillC = m_isActive ? COLOR_G : COLOR_R;

    this->m_shape->setFillColor(m_isOver ? fillC + sf::Color(20, 20, 20) : fillC);

    //isActive = false;
}

void CheckBox::Draw(sf::RenderTarget& _render)
{
    _render.draw(*m_shape);
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
    if (m_isOver)
    {
        m_isActive = !m_isActive;
    }
}

bool CheckBox::IsActive()
{
    return m_isActive;
}

bool CheckBox::IsOver()
{
    return m_isOver;
}

void CheckBox::CheckCollision(const sf::Vector2i& const _pos)
{
    sf::FloatRect floatR = this->m_shape->getGlobalBounds();
    sf::Vector2f vec = sf::Vector2f(_pos);
    m_isOver = CollisionRectPoint(floatR, vec);
    //std::cout << "x : " << vec.x << "y : " << vec.y << std::endl;
    //std::cout << (isOver ? "collision" : "No collision") << std::endl;
}
