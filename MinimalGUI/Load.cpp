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
	sf::Vector2f shapePos = sf::Vector2f(x, 40.f + 60.f * _data.widget.size());
	shape->setPosition(shapePos);

	sf::Text* text = new sf::Text();
	text->setFont(font);
	text->setCharacterSize(16);
	text->setString("Init");
	CenterTextOnShape(*text, *shape);

	Button* buttonInit = new Button(shape, text);

	buttonInit->SetOnClick([&game]() { game.Init(); });

	_data.widget.push_back(buttonInit);


	sf::RectangleShape* rshape = new sf::RectangleShape(sf::Vector2f(40.f, 40.f));
	rshape->setPosition(sf::Vector2f(x, 40.f + 60.f * _data.widget.size()));
	
	text = new sf::Text();
	text->setFont(font);
	text->setCharacterSize(16);
	text->setString("Pause");
	CenterTextOnShape(*text, *rshape);
	CheckBox* checkBox = new CheckBox(rshape, text);

	checkBox->SetOnToggle([&game](bool _on) { game.SetPause(_on); });

	_data.widget.push_back(checkBox);


	return 0;
}