#pragma once
#include "AnimatedObject.h"

class Turett : public AnimatedObject {
public:
	Turett(const sf::Vector2f&, const bool&);

	virtual void draw(float) const = 0;
	virtual sf::Sprite create(float) const = 0;
};