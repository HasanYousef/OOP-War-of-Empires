#pragma once

#include <SFML/Graphics.hpp>
#include "Empire.h"

class AI {
public:
	AI() : m_level(0), m_maxFighters(4), m_upTurretStand(true),
		m_score(0), m_giveMoney(true) {}
	void bot(Empire&);
private:
	sf::Clock m_clock;
	sf::Time m_levelTime;
	int m_maxFighters, m_level, m_score;
	bool m_upTurretStand, m_giveMoney;
};