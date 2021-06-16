#pragma once
#include "Turett.h"

Turett::Turett(const sf::Vector2f& p, const bool& objectTeam)
	: WorldObject(p, objectTeam), m_animationType(AnimationType::Idle){}

sf::Sprite AnimatedObject::create() const {
	
}