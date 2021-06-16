#pragma once

#include "Animation.h"
#include <iostream>

void Animation::set_anim_type(AnimationType anim) {
	m_currAnim = anim;
	m_currFrame = 0;
	m_totalTime = 0;
}

std::shared_ptr <sf::Texture> Animation::get_texture() const {
	if (AnimationType::GunFire == m_currAnim)
		return Textures::instance().get_gun_fire_texture(m_currFrame);
	return Textures::instance().get_animation_texture(m_fighterType, m_currAnim, m_currFrame);
}

AnimationType Animation::update(float deltaTime) {
	m_totalTime += deltaTime;

	if (m_totalTime >= ANIMATION_SWITCH_TIME && deltaTime !=0) {
		m_totalTime -= ANIMATION_SWITCH_TIME;
		m_currFrame++;
		if (m_currAnim != AnimationType::GunFire && 
			m_currFrame >= Textures::instance().num_of_anim_frames(m_fighterType, m_currAnim)) {
			m_currFrame = 0;
			m_currAnim = AnimationType::Idle;
		}
		else if (m_currAnim == AnimationType::GunFire && m_currFrame >= Textures::instance().num_of_gun_fire_frames()) {
			m_currFrame = 0;
		}
	}

	return m_currAnim;
}

int Animation::getCurrFrame() {
	return m_currFrame;
}