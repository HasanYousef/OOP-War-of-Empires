#pragma once

#include <SFML/Graphics.hpp>
#include "macros.h"
#include "Empire.h"

class AI {
public:
	AI() : m_level(0), m_maxFighters(4), m_tankInFront(false) {}
	void bot(std::shared_ptr <Empire> empire);
private:
	sf::Clock m_clock;
	sf::Time m_levelTime;
	int m_maxFighters, m_level;
	bool m_tankInFront;
};