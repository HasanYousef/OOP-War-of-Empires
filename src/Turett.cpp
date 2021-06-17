#pragma once
#include "Turett.h"

Turett::Turett(const sf::Vector2f& p, const bool& objectTeam)
	: WorldObject(p, objectTeam), m_animationType(AnimationType::Idle){
	AnimatedObject::reSetAnimationObject(TurettType::Turett1);
}

sf::Sprite Turett::create(float delta) const {
	auto result = sf::Sprite(*(AnimatedObject::getAnimationObject())->get_texture());
	if (m_isShooting)
		if (AnimatedObject::getAnimationObject()->update(delta))
			m_isShooting = false;
	result.setPosition(WorldObject::get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}