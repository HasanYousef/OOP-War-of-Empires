#pragma once
#include "Castle.h"

//-------------------------------------------------
Castle::Castle(const sf::Vector2f& p, const int& objectTeam)
	: LiveObject(p, objectTeam, CASTLE_HEALTH) {}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite Castle::create(float) const{
	sf::Sprite result = sf::Sprite(*Textures::instance().
		getWorldObjTexture(WorldObjectType::Castle));
	result.setPosition(getPosition());
	result.scale(0.625f, 0.625f);
	if (WorldObject::getObjectTeam() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
} 
