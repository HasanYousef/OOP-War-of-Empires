#pragma once

#include <vector>
#include "BuyWorldObject.h"
#include "CastleHealthbar.h"

class InGameUI {
public:
	InGameUI();
	void update(int, int, int);
	void draw() const;
	FighterType handle_click(const sf::Vector2f) const;
private:
	std::vector<BuyWorldObject> m_shop;
	CastleHealthbar m_leftCastleHealthbar,
		m_rightCastleHealthbar;
};
