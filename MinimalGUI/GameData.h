#pragma once

#include "Widget.h"
#include "LifeGame.h"
#include "common.h"
class GameData
{

public:
	GameData() : gameLife(sf::Vector2i(10, 10))
	{
	}

	sf::Font font;
	std::vector<Widget*> widget;
	sf::Vector2i mousePos;
	GameLife gameLife;
};
