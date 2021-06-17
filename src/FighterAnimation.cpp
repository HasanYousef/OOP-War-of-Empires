#pragma once

#include "FighterAnimation.h"

void FighterAnimation::set_anim_type(AnimationType anim) {
	m_currAnim = anim;
	m_currFrame = 0;
	m_totalTime = 0;
}

std::shared_ptr <sf::Texture> FighterAnimation::get_texture() const {
	return Textures::instance().get_animation_texture(m_fighterType, m_currAnim, m_currFrame);
}

AnimationType FighterAnimation::update(float deltaTime) {
	m_totalTime += deltaTime;

	if (m_totalTime >= ANIMATION_SWITCH_TIME && deltaTime != 0) {
		m_totalTime -= ANIMATION_SWITCH_TIME;
		m_currFrame++;
		if (m_currFrame >= Textures::instance().num_of_anim_frames(m_fighterType, m_currAnim)) {
			m_currFrame = 0;
			m_currAnim = AnimationType::Idle;
		}
	}

	return m_currAnim;
}