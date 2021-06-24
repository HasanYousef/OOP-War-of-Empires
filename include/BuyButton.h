#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class BuyButton : public Button {
public:
	BuyButton(sf::Vector2f, int);
	virtual void set_can_buy(bool);
	void set_can_buy_more(bool);
	void setPrice(int);
	int get_price() const;
	sf::Sprite create() const;
	virtual void draw() const;
	bool handle_click(const sf::Vector2f location);

protected:
	void draw_price() const;
	void draw_bought() const;

	bool m_canBuy = false;
	bool m_canBuyMore = true;
	int m_price;
};