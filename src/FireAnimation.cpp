#pragma once

#include "FireAnimation.h"

std::shared_ptr <sf::Texture> FireAnimation::get_texture() const {
	return Textures::instance().get_gun_fire_texture(m_currFrame);
}

bool FireAnimation::update(float delta) {
	return Animation::update(delta);
}