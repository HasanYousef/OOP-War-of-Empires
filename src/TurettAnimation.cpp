#pragma once

#include "TurettAnimation.h"

std::shared_ptr <sf::Texture> TurettAnimation::get_texture() const {
	return Textures::instance().get_turett_texture(m_turettType, m_currFrame);
}

bool TurettAnimation::update(float delta) {
	return Animation::update(delta);
}

void TurettAnimation::setIsShooting(bool is) {
	m_isShooting = is;
}

bool TurettAnimation::isShooting() const {
	return m_isShooting;
}

void TurettAnimation::set_anim() {
	m_currFrame = 0;
}