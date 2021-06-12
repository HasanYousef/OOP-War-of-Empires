#pragma once

#include "Animation.h"

void Animation::set_anim_type(AnimationType anim) {
	m_currAnim = anim;
	m_currFrame = 0;
}

std::shared_ptr <sf::Texture> Animation::get_texture() const {
	return Textures::instance().get_animation_texture(m_fighterType, m_currAnim, m_currFrame);
}

AnimationType Animation::update(float deltaTime) {
	m_totalTime += deltaTime;

	if (m_totalTime >= ANIMATION_SWITCH_TIME) {
		m_totalTime -= ANIMATION_SWITCH_TIME;
		m_currFrame++;
		if (m_currFrame >= Textures::instance().num_of_anim_frames(m_fighterType, m_currAnim)) {
			m_currFrame = 0;
			m_currAnim = AnimationType::Idle;
			if (m_currAnim == AnimationType::Attack || m_currAnim == AnimationType::Die)
				m_currAnim = AnimationType::Walk;
		}
	}

	return m_currAnim;
}

int Animation::getCurrFrame() {
	return m_currFrame;
}