#include "Slider.h"

Slider::Slider(sf::Vector2f _bound = sf::Vector2f(0.f, 100.f), float _current, sf::Shape* _shape, sf::Text* _text = nullptr)
{
    this->m_shape = _shape;
    m_isActive = false;
    m_isOver = false;
    m_shape->setOutlineColor(sf::Color(100, 100, 100));
    m_shape->setOutlineThickness(5.f);

    m_text = _text;

    m_bound = _bound;
    current = _current;
}

Slider::~Slider()
{
}

void Slider::Update()
{
}

void Slider::Draw(sf::RenderTarget& _render)
{
}

void Slider::MoosePos(const sf::Vector2i& _pos)
{
    CheckCollision(_pos);
}

void Slider::Pressed()
{
}

void Slider::Released()
{
}

void Slider::CheckCollision(const sf::Vector2i& _pos)
{
    sf::FloatRect floatR = this->m_shape->getGlobalBounds();
    sf::Vector2f vec = sf::Vector2f(_pos);
    m_isOver = CollisionRectPoint(floatR, vec);
}
