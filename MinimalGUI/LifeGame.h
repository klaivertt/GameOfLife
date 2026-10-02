#pragma once
#include "common.h"

class GameLife
{
public:
	GameLife(sf::Vector2i& _gridSize);
	~GameLife();

	void Update(float _dt);
	void Draw(sf::RenderStates& _render);
private:
};