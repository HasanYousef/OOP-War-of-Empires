#pragma once

#include <SFML/Graphics.hpp>
#include "BuyButton.h"

class BuyKiteBalloonButton : public BuyButton {
public:
	BuyKiteBalloonButton(sf::Vector2f pos, int price);
	sf::Sprite create() const;
	void draw() const;
	virtual void setCanBuy(bool);
	bool handleClick(const sf::Vector2f location);

private:
	void drawPrice() const;
	void drawBought() const;
	sf::Clock m_clock;
};