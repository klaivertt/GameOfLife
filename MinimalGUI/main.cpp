#include "common.h"
#include "GameData.h"
#include "Load.h"
#include "Update.h"
#include "Draw.h";

//---------------------------------------------------------------------------------
int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "MinimalGUI");

	GameData* data = new GameData();

	if (Load(*data) == -1)
	{
		return -1;
	}

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				window.close();
			}
			break;
			case sf::Event::Resized:
			{
				sf::FloatRect viewBounds(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(viewBounds));
			}
			break;
			case sf::Event::MouseButtonPressed:
			{
				// Todo handle mouse pressed
				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					for (size_t i = 0; i < data->widget.size(); i++)
					{
						data->widget[i]->Pressed();
					}
				}
			}
			break;
			case sf::Event::MouseButtonReleased:
			{
				for (size_t i = 0; i < data->widget.size(); i++)
				{
					data->widget[i]->Released();
				}
			}
			break;
			}
		}
		data->mousePos = sf::Mouse::getPosition(window);
		float deltaTime = clock.restart().asSeconds();
		Update(deltaTime, *data);

		window.clear(sf::Color::Black);

		Draw(window, *data);

		window.display();
	}

	for (size_t i = 0; i < data->widget.size(); i++)
	{
		Widget* widget = data->widget[i];
		delete widget;
	}

	data->widget.clear();

	delete data;

	return 0;
}
