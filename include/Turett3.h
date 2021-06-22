#pragma once

#include "Turett.h"

class Turett3 : public Turett {
public:
	Turett3(const sf::Vector2f&, bool);
	TurettType getType() const;
	int getDamage() const;
};
