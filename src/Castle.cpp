#pragma once
#include "Castle.h"

//-------------------------------------------------
Castle::Castle(const sf::Vector2f& p, const int& objectTeam)
	: LiveObject(p, objectTeam, CASTLE_HEALTH) {}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite Castle::create(float) const{
	sf::Sprite result = sf::Sprite(*Textures::instance().
		get_world_obj_texture(WorldObjectType::Castle));
	result.setPosition(get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
} 
