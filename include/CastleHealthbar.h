#pragma once

#include <SFML/Graphics.hpp>
#include "UIObject.h"
#include "CastleHealthbarBackground.h"

class CastleHealthbar {
public:
	CastleHealthbar(bool, int);
	void draw() const;

private:
	bool m_team;
	int m_maxHealth;
	CastleHealthbarBackground m_background;
};