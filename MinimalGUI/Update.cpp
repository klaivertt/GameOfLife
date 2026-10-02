#include "Update.h"
#include "GameData.h"
void Update(float _dt, GameData& _data)
{
	for (size_t i = 0; i < _data.widget.size(); i++)
	{
		_data.widget[i]->MoosePos(_data.mousePos);
		_data.widget[i]->Update();
	}

}
