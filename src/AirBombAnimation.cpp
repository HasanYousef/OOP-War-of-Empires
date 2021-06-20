#pragma once
#include "AirBombAnimation.h"

std::shared_ptr <sf::Texture> AirBombAnimation::get_texture() const {
	if (!m_explosive)
		return Textures::instance().get_bomb_texture(m_airBombModule);
	else
		return Textures::instance().get_explosion_texture(m_currFrame);
}

bool AirBombAnimation::update(float delta) {
	if (m_explosive)
		return Animation::update(delta);
	return Animation::update(0);
}

void AirBombAnimation::set_anim() {
	m_currFrame = 0;
	m_explosive = true;
}