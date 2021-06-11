#pragma once

#include "MatchBackground.h"

MatchBackground::MatchBackground() : WorldObject({0, 0})
{}

sf::Sprite MatchBackground::create(float) const {
	return sf::Sprite(*Textures::instance().
		get_world_obj_texture(WorldObjectType::MatchBackground));
}

