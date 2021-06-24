#pragma once

#include <SFML/Graphics.hpp>
#include "Empire.h"

class AI {
public:
	AI() : m_level(0), m_maxFighters(4), m_tankFront(false),
		 m_giveMoney(true), m_wave(0) {}
	void bot(Empire&);
private:
	void levelUp();
	void buyTurret(Empire&);
	//---Members----------
	sf::Clock m_clock;
	sf::Time m_levelTime;
	int m_maxFighters, m_level, m_wave;
	bool m_tankFront, m_giveMoney;
};