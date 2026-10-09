#include "Load.h"
#include "GameData.h"
#include "Button.h"
#include "CheckBox.h"
#include "Slider.h"

int Load(GameData& _data)
{
	srand((unsigned int)(time(NULL)));

	sf::Font& font = _data.font;
	if (!font.loadFromFile("arial.ttf"))
	{
		return -1;
	}

	int sizeGrid = 80;
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
	
	rshape = new sf::RectangleShape(sf::Vector2f(100.f, 25.f));
	rshape->setPosition(sf::Vector2f(x-75.f, 40.f + 60.f * _data.widget.size()));
	rshape->setFillColor(sf::Color(75,180,120));
	
	text = new sf::Text();
	text->setFont(font);
	text->setCharacterSize(16);
	text->setString("Life Rate :");

	CenterTextOnShape(*text, *rshape);
	Slider* slider = new Slider(sf::Vector2f(0.f,1.f), 0.5f, rshape, text);

	slider->SetOnReleased([&game](float _percent) { game.SetLifePercent(_percent); });

	_data.widget.push_back(slider);

	return 0;
}