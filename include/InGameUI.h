#pragma once

#include <vector>
#include "BuyFighter.h"
#include "BuyTurett.h"
#include "BuyKiteBalloon.h"
#include "CastleHealthbar.h"

class InGameUI {
public:
	InGameUI();
	void update(int, int, int);
	void draw() const;
	void drawMoney(int) const;
	void setTurettType(int, int);
	FighterType handleClickFighters(const sf::Vector2f) const;
	int handleClickTuretts(const sf::Vector2f) const;
	bool handleClickBalloon(const sf::Vector2f) const;
private:
	std::vector<std::unique_ptr<BuyWorldObject>> m_shop;
	CastleHealthbar m_leftCastleHealthbar,
		m_rightCastleHealthbar;
	std::unique_ptr<BuyKiteBalloon> m_kiteBalloon;
	int m_money = 0;
};
