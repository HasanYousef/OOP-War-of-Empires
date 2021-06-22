#pragma once
#include "RangeFighter.h"

class RangeFighter1 : public RangeFighter {
public:
	RangeFighter1() = default;
	RangeFighter1(const sf::Vector2f&,
		const int&, const int&, const int&, const int&);

	static void init_level() {
		m_level = 1;
	}
	static void level_up() {
		m_level++;
	}

private:
	static int m_level;
};