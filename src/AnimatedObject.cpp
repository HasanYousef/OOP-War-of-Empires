#pragma once
#include "AnimatedObject.h"

//-------------------------------------------------
AnimatedObject::AnimatedObject(const sf::Vector2f& p) 
	: WorldObject(p), m_animationType(AnimationType::Walk){}

AnimatedObject::AnimatedObject(const sf::Vector2f& p, const bool& objectTeam)
	: WorldObject(p, objectTeam), m_animationType(AnimationType::Walk){}

//-------------------------------------------------
void AnimatedObject::setAnimationType(const AnimationType& newAnimationType){
	m_animationType = newAnimationType;
}

//-------------------------------------------------
AnimationType AnimatedObject::getAnimationType() const{
	return m_animationType;
}

//-------------------------------------------------
//we creat the texture that we want to print it 
/*
sf::Sprite AnimatedObject::create() const {
	sf::Sprite result = sf::Sprite(*Animation::instance().
		get_texture(get_type(), m_currentAnimationType, m_lastAnimationType));
	result.setPosition(get_position());
	result.getPosition();
	// 40 = width of texture, 50 = height of texture
	result.setTextureRect(sf::IntRect(40, 0, 40 * get_object_team(), 50));
	return result;
} */