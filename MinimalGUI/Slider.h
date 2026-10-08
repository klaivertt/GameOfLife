#pragma once

#include "Widget.h"

class Slider : Widget
{
private:
	using Callback = std::function<void(float)>;
public:
	Slider(sf::Vector2f _bound = sf::Vector2f(0.f, 100.f), float _current, sf::Shape* _shape, sf::Text* _text = nullptr);
	~Slider();

	void Update() override;
	void Draw(sf::RenderTarget& _render) override;

	void MoosePos(const sf::Vector2i& _pos) override;
	void Pressed() override;
	void Released() override;
private:
	sf::Vector2f m_bound;
	sf::Shape* m_shape;
	sf::Shape* m_shapeOutline;
	sf::Text* m_text;
	void CheckCollision(const sf::Vector2i& _pos) override;
};