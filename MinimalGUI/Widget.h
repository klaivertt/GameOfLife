#pragma once
#include "common.h"

#define COLOR_R sf::Color(200,50,50)
#define COLOR_G sf::Color(50,200,50)

class Widget
{
public:
	virtual ~Widget() = default;

	virtual void Update() = 0;
	virtual void Draw(sf::RenderTarget& _render) = 0;

	virtual void MoosePos(const sf::Vector2i& _pos) = 0;
	virtual void Pressed() = 0;
	virtual void Released() = 0;

	virtual bool IsActive() = 0;
	virtual bool IsOver() = 0;
protected:
	bool isActive;
	bool isOver;

	virtual void CheckCollision(const sf::Vector2i& _pos) = 0;
};