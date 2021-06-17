#pragma once

#include "FireAnimation.h"

std::shared_ptr <sf::Texture> FireAnimation::get_texture() const {
	Textures::instance().get_gun_fire_texture(Animation::getCurrFrame());
}

bool FireAnimation::update(float delta) {
	return Animation::update(delta);
}