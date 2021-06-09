#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Sounds.h"
#include "Textures.h"
#include "MatchBackground.h"
#include "Empire.h"

class Match {
public:
	void run();

private:
	void draw_world(float);
	MatchBackground m_background;
	Empire m_enemyEmpire, m_playerEmpire;
};
