#pragma once
#include "Floor.h"

Floor::Floor() : WorldObject({ 0, 1015 }) {};

sf::Sprite Floor::create(float) const {
	sf::Sprite result = sf::Sprite(*Textures::instance().
		get_world_obj_texture(WorldObjectType::Floor));
	result.setPosition(get_position());
	return result;
}