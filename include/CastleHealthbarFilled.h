#pragma once

#include <SFML/Graphics.hpp>
#include "UIObject.h"

class CastleHealthbarFilled : UIObject {
public:
	CastleHealthbarFilled(bool);
	void update(int);
	void draw() const;
private:
	sf::Sprite create() const;
	int m_currHealth;
	int m_maxHealth;
};