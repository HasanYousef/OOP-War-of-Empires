#pragma once
#include "RangeFighter.h"

class RangeFighter2 : public RangeFighter {
public:
	RangeFighter2() = default;
	RangeFighter2(const sf::Vector2f&,
		const int&, const int&, const int&, const int&);
};