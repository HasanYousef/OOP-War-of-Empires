#pragma once

#include <vector>
#include "BuyWorldObject.h"

class InGameUI {
public:
	InGameUI();
	void update(int);
	void draw() const;
	FighterType handle_click(const sf::Vector2f) const;
private:
	std::vector<BuyWorldObject> m_shop;
};
