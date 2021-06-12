#pragma once

#include <SFML/Graphics.hpp>
#include "UIObject.h"
#include "CastleHealthbarBackground.h"
#include "CastleHealthbarFilled.h"

class CastleHealthbar {
public:
	CastleHealthbar(bool, int);
	void draw() const;
	void update(int);

private:
	CastleHealthbarBackground m_background;
	CastleHealthbarFilled m_filled;
};