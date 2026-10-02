#pragma once

#include "Widget.h"

class Button : public Widget
{
public:
	Button(sf::Shape* _shape);
	void Update() override;
	void Draw(sf::RenderTarget& _render) override;

	void MoosePos(const sf::Vector2i& _pos) override;
	void Pressed() override;
	void Released() override;

	bool IsActive() override;
	bool IsOver() override;
protected:
	sf::Shape* shape;
	void CheckCollision(const sf::Vector2i& _pos) override;
};