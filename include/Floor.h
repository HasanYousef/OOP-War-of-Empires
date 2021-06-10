#pragma once
#include "WorldObject.h"

class Floor : WorldObject {
public:
	Floor() = default ;
	Floor(const sf::Vector2f&);

	//---build-body-----------
	virtual void draw(float) const;
	virtual sf::Sprite create(float) const;
};