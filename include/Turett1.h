#pragma once

#include "Turett.h"

class Turett1 : public Turett {
public:
	Turett1(const sf::Vector2f&, bool);
	TurettType getType() const;
	int getDamage() const;
};
