#pragma once

#include <SFML/Graphics.hpp>
#include "WorldObject.h"

class MatchBackground : public WorldObject {
public:
	MatchBackground();
	sf::Sprite create(float) const;
};