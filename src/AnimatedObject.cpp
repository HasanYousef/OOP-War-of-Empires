#pragma once
#include "AnimatedObject.h"

//-------------------------------------------------
AnimatedObject::AnimatedObject(const sf::Vector2f& p)
	: WorldObject(p) {}

AnimatedObject::AnimatedObject(const sf::Vector2f& p, const bool& objectTeam)
	: WorldObject(p, objectTeam) {}
