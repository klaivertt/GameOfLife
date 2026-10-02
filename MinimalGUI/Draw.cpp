#include "Draw.h"
#include "GameData.h"

void Draw(sf::RenderTarget& _render, GameData& _data)
{
	for (size_t i = 0; i < _data.widget.size(); i++)
	{
		_data.widget[i]->Draw(_render);
	}
}
