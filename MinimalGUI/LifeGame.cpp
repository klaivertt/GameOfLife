#include "LifeGame.h"

GameLife::GameLife(sf::Vector2i _gridSize, float _updateTime)
{
	gridSize = _gridSize;
	time = 0; 
	updateTime = _updateTime;

	float sSize = (SCREEN_S.y - MARGIN.y * 5);
	cellSize = sf::Vector2f(sSize / gridSize.x, sSize / gridSize.y);


	gridRect.setSize(sf::Vector2f(cellSize.x, cellSize.y));
	gridRect.setFillColor(sf::Color::Transparent);
	gridRect.setOutlineColor(sf::Color(140, 140, 140));
	gridRect.setOutlineThickness(1.f);


	grid = std::vector<std::vector<sf::RectangleShape>> (gridSize.y,
		std::vector<sf::RectangleShape>(gridSize.x));

	cellAlive = std::vector<std::vector<bool>> (gridSize.y,
		std::vector<bool>(gridSize.x));

	for (int y = 0; y < gridSize.y; ++y)
	{
		for (int x = 0; x < gridSize.x; ++x)
		{
			grid[y][x].setSize(cellSize);
			grid[y][x].setPosition(
				cellSize.x * x + MARGIN.x,
				cellSize.y * y + MARGIN.y
			);
			cellAlive[y][x] = Random(0, 100) >= 60 ? true : false;

			grid[y][x].setFillColor(cellAlive[y][x] ? sf::Color::White : sf::Color::Transparent);
		}
	}
}

GameLife::~GameLife()
{
}

void GameLife::Update(float _dt)
{
	time += _dt;
	bool isUpdate = false;
	if (updateTime < time)
	{
		time -= updateTime;
		isUpdate = true;
	}

	if (isUpdate)
	{
		std::vector<std::vector<bool>> copyCellAlive = cellAlive;

		for (int y = 0; y < gridSize.y; ++y)
		{
			for (int x = 0; x < gridSize.x; ++x)
			{
				bool isCallAlive = copyCellAlive[y][x];
			}
		}
	}

}

void GameLife::Draw(sf::RenderTarget& _render)
{
	for (int y = 0; y < gridSize.y; y++)
	{
		for (int x = 0; x < gridSize.x; x++)
		{
			_render.draw(grid[y][x]);

			gridRect.setPosition(sf::Vector2f(cellSize.x * x + MARGIN.x, cellSize.y * y + MARGIN.y));
			_render.draw(gridRect);
		}
	}
}
