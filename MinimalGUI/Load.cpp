#include "Load.h"
#include "GameData.h"
#include "Button.h"
#include "CheckBox.h"
int Load(GameData& _data)
{
	srand((unsigned int)(time(NULL)));

	sf::Font& font = _data.font;
	if (!font.loadFromFile("arial.ttf"))
	{
		return -1;
	}

	int sizeGrid = 60;
	_data.gameLife = GameLife(sf::Vector2i(sizeGrid, sizeGrid), 0.5f);

	GameLife& game = _data.gameLife;

	float x = SCREEN_S.x - 80.f;

	sf::CircleShape* shape = new sf::CircleShape(20.f);
	shape->setPosition(sf::Vector2f(x, 40.f + 60.f * _data.widget.size()));

	Button* buttonInit = new Button(shape);

	buttonInit->SetOnClick([&game]() { game.Init(); });

	_data.widget.push_back(buttonInit);


	sf::RectangleShape* rshape = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
	rshape->setPosition(sf::Vector2f(x, 40.f + 60.f * _data.widget.size()));
	CheckBox* checkBox = new CheckBox(rshape);

	checkBox->SetOnToggle([&game](bool _on) { game.SetPause(_on); });

	_data.widget.push_back(checkBox);


	return 0;
}