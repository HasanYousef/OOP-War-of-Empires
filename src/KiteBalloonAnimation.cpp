#pragma once
#include "KiteBalloonAnimation.h"

std::shared_ptr <sf::Texture> KiteBalloonAnimation::getTexture() const {
	return Textures::instance().getKiteBalloonTexture((m_kiteLevel > 2)? 2: m_kiteLevel, m_currFrame);
}

bool KiteBalloonAnimation::update(float deltaTime) {
	m_totalTime += deltaTime;

	if (m_totalTime >= ANIMATION_SWITCH_TIME && deltaTime != 0) {
		m_totalTime -= ANIMATION_SWITCH_TIME;
		if (m_riseMode) {
			m_currFrame++;
			if (m_currFrame >= NUM_OF_FIRE_ANIMATION_FRAMES) {
				//m_currFrame = 0;
				m_riseMode = false;
				return true;
			}
		}
		else {
			m_currFrame--;
			if (m_currFrame <= 0) {
				//m_currFrame = 0;
				m_riseMode = true;
				return true;
			}
		}
	}

	return false;
}

void KiteBalloonAnimation::setAnim() {
	m_currFrame = 0;
}

void KiteBalloonAnimation::setKiteLevel(int newKiteLevel) {
	m_kiteLevel = newKiteLevel;
}