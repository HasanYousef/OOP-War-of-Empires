#pragma once

#include <vector>
#include "BuyFighter.h"
#include "BuyTurett.h"
#include "CastleHealthbar.h"

class InGameUI {
public:
	InGameUI();
	void update(int, int, int);
	void draw() const;
	void drawMoney(int) const;
	void setTurettType(int, int);
	FighterType handle_click_fighters(const sf::Vector2f) const;
	int handle_click_turetts(const sf::Vector2f) const;
private:
	std::vector<std::unique_ptr<BuyWorldObject>> m_shop;
	CastleHealthbar m_leftCastleHealthbar,
		m_rightCastleHealthbar;
	int m_money = 0;
};
