#pragma once

#include <SFML/Graphics.hpp>
#include "BuyButton.h"

class BuyKiteBalloonButton : public BuyButton {
public:
	BuyKiteBalloonButton(sf::Vector2f pos, int price);
	sf::Sprite create() const;
	void draw() const;
	virtual void set_can_buy(bool);
	bool handle_click(const sf::Vector2f location);

private:
	void draw_price() const;
	void draw_bought() const;
	/*
	bool m_canBuy = false;
	bool m_canBuyMore = true;
	int m_price;*/
	sf::Clock m_clock;
};