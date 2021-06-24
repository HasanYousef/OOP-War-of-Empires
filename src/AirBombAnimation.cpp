#pragma once
#include "AirBombAnimation.h"

std::shared_ptr <sf::Texture> AirBombAnimation::getTexture() const {
	if (!m_explosive)
		return Textures::instance().getBombTexture((m_airBombModule > 3)? 3:m_airBombModule);
	else
		return Textures::instance().getExplosionTexture((m_airBombModule > 2) ? 2 : m_airBombModule,m_currFrame);
}

bool AirBombAnimation::update(float delta) {
	if (m_explosive) {
		m_totalTime += delta;

		if (m_totalTime >= ANIMATION_SWITCH_TIME && delta != 0) {
			m_totalTime -= ANIMATION_SWITCH_TIME;
			m_currFrame++;
			if (m_currFrame >= 25) {
				m_currFrame = 0;
				return true;
			}
		}

		return false;
	}
	return Animation::update(0);
}

void AirBombAnimation::setAnim() {
	m_currFrame = 0;
	m_explosive = true;
}

void AirBombAnimation::setAnimModule(int airBombModule) {
	if (airBombModule >= 1 && airBombModule <= 3)
		m_airBombModule = airBombModule;
}