#include "Update.h"
#include "GameData.h"
void Update(float _dt, GameData& _data)
{
	_data.gameLife.Update(_dt);
	for (size_t i = 0; i < _data.widget.size(); i++)
	{
		_data.widget[i]->Update(_data.mousePos);
	}

}
