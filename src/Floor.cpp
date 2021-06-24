#pragma once
#include "Floor.h"

Floor::Floor() : WorldObject({ 0, 1015 }) {};

sf::Sprite Floor::create(float) const {
	sf::Sprite result = sf::Sprite(*Textures::instance().
		getWorldObjTexture(WorldObjectType::Floor));
	result.setPosition(getPosition());
	return result;
}