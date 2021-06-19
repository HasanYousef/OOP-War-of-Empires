#pragma once

#include "Animation.h"

int Animation::getCurrFrame() {
	return m_currFrame;
}

bool Animation::update(float deltaTime) {
	m_totalTime += deltaTime;

	if (m_totalTime >= ANIMATION_SWITCH_TIME && deltaTime != 0) {
		m_totalTime -= ANIMATION_SWITCH_TIME;
		m_currFrame++;
		if (m_currFrame >= NUM_OF_FIRE_ANIMATION_FRAMES) {
			m_currFrame = 0;
			return true;
		}
	}

	return false;
}