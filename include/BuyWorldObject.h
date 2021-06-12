#pragma once

#include <SFML/Graphics.hpp>
#include "BuyButton.h"
#include "BuyWorldObjectBackground.h"

class BuyWorldObject {
public:
	BuyWorldObject(FighterType, sf::Vector2f, int);
	void set_can_buy(bool);
	int get_price();
	void draw() const;
	bool handle_click(const sf::Vector2f location) const;

private:
	void draw_fighter() const;
	//---Members----------
	BuyWorldObjectBackground m_background;
	std::unique_ptr<BuyButton> m_button;
	sf::Vector2f m_position;
	FighterType m_fighterType;
};
