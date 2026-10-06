#pragma once
#include "common.h"

#define MARGIN sf::Vector2f(25.f, 25.f)

class GameLife
{
public:
	GameLife(sf::Vector2i _gridSize);
	~GameLife();

	void Update(float _dt);
	void Draw(sf::RenderTarget& _render);
private:

	sf::Vector2i gridSize;
	std::vector<std::vector<sf::RectangleShape>> grid;
	sf::RectangleShape gridRect;
	sf::Vector2f cellSize;
};