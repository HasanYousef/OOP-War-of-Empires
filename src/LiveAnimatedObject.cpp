#pragma once
#include "LiveAnimatedObject.h"

//-------------------------------------------------
LiveAnimatedObject::LiveAnimatedObject() {}

LiveAnimatedObject::LiveAnimatedObject(const WorldObjectType& type, const sf::Vector2f& p,
	const int& objectTeam, const int& health)
	: AnimatedObject(type, p, objectTeam), LiveObject(type, p, objectTeam, health) {}

//-------------------------------------------------
//this func draw the object
sf::Sprite LiveAnimatedObject::create() const {
	sf::Sprite result = sf::Sprite(*Animation::instance().
		get_texture(AnimatedObject::get_type(), 
			AnimatedObject::getCurrentAnimationType(), 
			AnimatedObject::getLastAnimationType()));

	result.setPosition(AnimatedObject::get_position());
	result.getPosition();
	// 40 = width of texture, 50 = height of texture
	result.setTextureRect(sf::IntRect(40, 0, 40 * AnimatedObject::get_object_team(), 50));
	return result;
}\