#pragma once
/*
#include "Animation.h"

Animation& Animation::instance() {
	static Animation inst;
	return inst;
}

void Animation::update(float deltaTime) {
	m_totalTime += deltaTime;

	if (m_totalTime >= ANIMATION_SWITCH_TIME) {
		m_totalTime -= ANIMATION_SWITCH_TIME;
		m_currentImage++;
		if (m_currentImage >= ANIMATION_IMAGE_COUNT)
			m_currentImage = 0;
	}
}

sf::IntRect Animation::get_rect(WorldObjectType object, ) const {
	Textures::instance().get_animation_texture()
}*/