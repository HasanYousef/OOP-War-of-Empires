#pragma once 
#include "FireAnimation.h"

std::shared_ptr <sf::Texture> FireAnimation::getTexture() const {
	return Textures::instance().getGunFireTexture(m_currFrame);
}

void FireAnimation::setAnim() {
	m_currFrame = 0;
}