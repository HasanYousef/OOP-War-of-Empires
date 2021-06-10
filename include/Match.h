#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Sounds.h"
#include "Textures.h"
#include "MatchBackground.h"
#include "Floor.h"
#include "Empire.h"

#include "MeleeFighter.h" // @$#%@#$%@#$%@#$%@#$%

class Match {
public:
	Match() : m_floor({0, 1015}) {
		for (int i = 0; i < 10; i++) {
			int x = 100 + i * 90;
			m_fighters.push_back(new MeleeFighter(sf::Vector2f(x, 927), true, 100, 10, 10));
		}
	}
	void run();

private:
	void draw_world(float);
	MatchBackground m_background;
	Floor m_floor;
	Empire m_enemyEmpire, m_playerEmpire;
	std::vector <MeleeFighter*> m_fighters;
};
