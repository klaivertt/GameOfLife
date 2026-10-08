#pragma once

#include "Widget.h"


class Button : public Widget
{
private:
	using Callback = std::function<void()>;
public:

	Button(sf::Shape* _shape, sf::Text* _text = nullptr);
	~Button();
	void Update() override;
	void Draw(sf::RenderTarget& _render) override;

	void MoosePos(const sf::Vector2i& _pos) override;
	void Pressed() override;
	void Released() override;

	void SetOnClick(Callback _cb);
protected:
	sf::Shape* m_shape;
	Callback m_onClick;
	sf::Text* m_text;
	void CheckCollision(const sf::Vector2i& _pos) override;
};