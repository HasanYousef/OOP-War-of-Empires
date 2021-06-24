#pragma once

#include "TurettAnimation.h"

std::shared_ptr <sf::Texture> TurettAnimation::getTexture() const {
	return Textures::instance().getTurettTexture(m_turettType, m_currFrame);
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

void TurettAnimation::setAnim() {
	m_currFrame = 0;
}