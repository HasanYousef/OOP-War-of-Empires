#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class BuyButton : public Button {
public:
	BuyButton(sf::Vector2f, int);
	void setCanBuy(bool);
	sf::Sprite create() const;
	void draw() const;
	void draw_price() const;
	bool handle_click(const sf::Vector2f location) const;

private:
	bool m_canBuy = false;
	int m_price;
};