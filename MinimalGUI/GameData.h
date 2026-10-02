#pragma once

#include "Widget.h"
#include "common.h"
class GameData
{
public:
	sf::Font font;
	std::vector<Widget*> widget;
	sf::Vector2i mousePos;
};
