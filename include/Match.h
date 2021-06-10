#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Sounds.h"
#include "Textures.h"
#include "MatchBackground.h"
#include "Floor.h"
#include "Empire.h"

class Match {
public:
	Match() : m_floor({ 0, 1015 }) {}
	void run();

private:
	void draw_world(float);
	MatchBackground m_background;
	Floor m_floor;
	Empire m_enemyEmpire, m_playerEmpire;
};
