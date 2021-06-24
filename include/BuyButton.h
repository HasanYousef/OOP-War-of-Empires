#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class BuyButton : public Button {
public:
	BuyButton(sf::Vector2f, int);
	virtual void setCanBuy(bool);
	void setCanBuyMore(bool);
	void setPrice(int);
	int getPrice() const;
	sf::Sprite create() const;
	virtual void draw() const;
	bool handleClick(const sf::Vector2f location);

protected:
	void drawPrice() const;
	void drawBought() const;

	bool m_canBuy = false;
	bool m_canBuyMore = true;
	int m_price;
};