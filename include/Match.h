#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Sounds.h"
#include "Textures.h"
#include "MatchBackground.h"
#include "InGameUI.h"
#include "Floor.h"
#include "Empire.h"

#include "Bullet.h" //$!@#$@#%@#$%@#$%R#@%@$%@#$%

class Match {
public:
	Match();
	void run();

private:
	void draw_world(float);
	void buyFighter(const sf::Vector2f&);
	//---------------------------
	MatchBackground m_background;
	InGameUI m_UI;
	Floor m_floor;
	Empire m_enemyEmpire, m_playerEmpire;
	Bullet m_bullet;
};
