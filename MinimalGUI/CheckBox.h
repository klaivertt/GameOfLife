#pragma once
#include "Widget.h"



class CheckBox : public Widget
{
private:
	using Callback = std::function<void(bool)>;
public:
	CheckBox(sf::Shape* _shape);
	~CheckBox();
	void Update() override;
	void Draw(sf::RenderTarget& _render) override;

	void MoosePos(const sf::Vector2i& _pos) override;
	void Pressed() override;
	void Released() override;

	void SetOnToggle(Callback _cb);

protected :
	sf::Shape* m_shape;
	Callback m_onToggle;
	bool m_isPressed;

	virtual void CheckCollision(const sf::Vector2i& _pos) override;
};
