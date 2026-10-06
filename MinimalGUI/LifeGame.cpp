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


	grid = std::vector<std::vector<sf::RectangleShape>>(gridSize.y,
		std::vector<sf::RectangleShape>(gridSize.x));

	cellAlive = std::vector<std::vector<bool>>(gridSize.y,
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
			cellAlive[y][x] = Random(0, 100) >= 55 ? true : false;

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
	if (updateTime < time)
	{
		time -= updateTime;

		std::vector<std::vector<bool>> copyCellAlive = cellAlive;

		for (int i = 0; i < gridSize.y; i++)
		{
			for (int j = 0; j < gridSize.x; j++)
			{
				bool isCellAlive = copyCellAlive[i][j];
				int countCellAlive = 0;

				for (int y = -1; y <= 1; y++)
				{
					for (int x = -1; x <= 1; x++)
					{
						int finalX = j + x;
						int finalY = i + y;

						bool isNotSelf = (x != 0 || y != 0);
						bool isInGrid = finalX >= 0 && finalX < gridSize.x && finalY >= 0 && finalY < gridSize.y;

						if (isNotSelf && isInGrid && copyCellAlive[finalY][finalX])
						{
							countCellAlive++;
						}
					}
				}

				if (isCellAlive)
				{
					cellAlive[i][j] = (countCellAlive == 2 || countCellAlive == 3);
				}
				else
				{
					cellAlive[i][j] = (countCellAlive == 3);
				}

				grid[i][j].setFillColor(cellAlive[i][j] ? sf::Color::White : sf::Color::Transparent);
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
