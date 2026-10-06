#include "LifeGame.h"

GameLife::GameLife(sf::Vector2i _gridSize)
{
	gridSize = _gridSize;
	float sSize = (SCREEN_S.y - MARGIN.y * 5);
	cellSize = sf::Vector2f(sSize / gridSize.x, sSize / gridSize.y);

	std::vector<std::vector<sf::RectangleShape>> grid(gridSize.y,
		std::vector<sf::RectangleShape>(gridSize.x));

	gridRect.setSize(sf::Vector2f(cellSize.x, cellSize.y));
	gridRect.setFillColor(sf::Color::Transparent);
	gridRect.setOutlineColor(sf::Color(140, 140, 140));
	gridRect.setOutlineThickness(1.f);

	for (int y = 0; y < gridSize.y; ++y)
	{
		for (int x = 0; x < gridSize.x; ++x)
		{
			grid[y][x].setSize(cellSize);
			grid[y][x].setPosition(
				x * cellSize.x,
				y * cellSize.y
			);
			grid[y][x].setFillColor(sf::Color::Transparent);
		}
	}
}

GameLife::~GameLife()
{
}

void GameLife::Update(float _dt)
{
}

void GameLife::Draw(sf::RenderTarget& _render)
{
	for (int y = 0; y < gridSize.y; y++)
	{
		for (int x = 0; x < gridSize.x; x++)
		{
			gridRect.setPosition(sf::Vector2f(cellSize.x * x + MARGIN.x, cellSize.y * y + MARGIN.y));
			_render.draw(gridRect);
			_render.draw(grid[y][x]);
		}
	}
}
