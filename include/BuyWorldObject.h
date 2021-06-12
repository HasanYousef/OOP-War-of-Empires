#pragma once

#include <SFML/Graphics.hpp>
#include "BuyButton.h"
#include "BuyWorldObjectBackground.h"

class BuyWorldObject {
public:
	BuyWorldObject(FighterType, sf::Vector2f, int);
	void draw() const;
	void draw_fighter() const;

private:
	BuyWorldObjectBackground m_background;
	std::unique_ptr<BuyButton> m_button;
	sf::Vector2f m_position;
	FighterType m_fighterType;
};
