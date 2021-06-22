#pragma once

#include "Turett.h"

class Turett2 : public Turett {
public:
	Turett2(const sf::Vector2f&, bool);
	TurettType getType() const;
	int getDamage() const;
};
