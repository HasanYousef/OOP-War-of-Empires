#pragma once

#include <SFML/Graphics.hpp>
#include "BuyButton.h"
#include "BuyWorldObjectBackground.h"

class BuyWorldObject {
public:
	BuyWorldObject(sf::Vector2f, int);
	void setCanBuy(bool);
	int getPrice();
	virtual void setType(int) = 0;
	void draw() const;
	virtual bool handleClick(const sf::Vector2f location) const;

protected:
	virtual void drawObject() const = 0;

	BuyWorldObjectBackground m_background;
	std::unique_ptr<BuyButton> m_button;
	sf::Vector2f m_position;
};
