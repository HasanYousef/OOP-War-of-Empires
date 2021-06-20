#pragma once

#include <SFML/Graphics.hpp>
#include "BuyButton.h"
#include "BuyWorldObjectBackground.h"

class BuyWorldObject {
public:
	BuyWorldObject(sf::Vector2f, int);
	void set_can_buy(bool);
	int get_price();
	void draw() const;
	bool handle_click(const sf::Vector2f location) const;

protected:
	virtual void draw_object() const = 0;

	BuyWorldObjectBackground m_background;
	std::unique_ptr<BuyButton> m_button;
	sf::Vector2f m_position;
};
