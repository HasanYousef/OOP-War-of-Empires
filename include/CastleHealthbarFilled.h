#pragma once

#include <SFML/Graphics.hpp>
#include "UIObject.h"

class CastleHealthbarFilled : UIObject {
public:
	CastleHealthbarFilled(bool, float);
	void update(int);
	void draw() const;
private:
	sf::Sprite create() const;
	void drawText() const;
	float m_currHealth;
	float m_maxHealth;
};