#pragma once
#include "RangeFighter.h"

class RangeFighter1 : public RangeFighter {
public:
	RangeFighter1() = default;
	RangeFighter1(const sf::Vector2f&, const int&);
	void addLevel();
};