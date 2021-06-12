#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class BuyButton : public Button {
public:
	BuyButton(sf::Vector2f, int);
	void set_can_buy(bool);
	int get_price() const;
	sf::Sprite create() const;
	void draw() const;
	bool handle_click(const sf::Vector2f location) const;

private:
	void draw_price() const;
	bool m_canBuy = false;
	int m_price;
};