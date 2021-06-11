#pragma once

#include <SFML/Graphics.hpp>
#include "WorldObject.h"

class Floor : public WorldObject {
public:
	Floor();
	sf::Sprite create(float) const;
};