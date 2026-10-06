#include "Load.h"
#include "GameData.h"
#include "Button.h"
#include "CheckBox.h"
int Load(GameData& _data)
{
	sf::Font& font = _data.font;
	if (!font.loadFromFile("arial.ttf"))
	{
		return -1;
	}
	float x = SCREEN_S.x - 80.f;
	for (size_t i = 0; i < 2; i++)
	{
		sf::CircleShape* shape = new sf::CircleShape(20.f);
		shape->setPosition(sf::Vector2f(x, 40.f + 60.f * _data.widget.size()));
		_data.widget.push_back(new Button(shape));
	}
	for (size_t i = 0; i < 2; i++)
	{
		sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
		shape->setPosition(sf::Vector2f(x, 40.f + 60.f * _data.widget.size()));
		_data.widget.push_back(new Button(shape));
	}
	for (size_t i = 0; i < 3; i++)
	{
		sf::CircleShape* shape = new sf::CircleShape(20.f);
		shape->setPosition(sf::Vector2f(x, 40.f + 60.f * _data.widget.size()));
		_data.widget.push_back(new CheckBox(shape));
	}
	for (size_t i = 0; i < 2; i++)
	{
		sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
		shape->setPosition(sf::Vector2f(x, 40.f + 60.f * _data.widget.size()));
		_data.widget.push_back(new CheckBox(shape));
	}

	_data.gameLife = GameLife(sf::Vector2i(50, 50));

	return 0;
}