#pragma once
#include "AnimatedObject.h"

//-------------------------------------------------
AnimatedObject::AnimatedObject() {}

AnimatedObject::AnimatedObject(const WorldObjectType& type,
	const sf::Vector2f& p) 
	: WorldObject(type,p), m_currentAnimationType(AnimationType::Idle){}

AnimatedObject::AnimatedObject(const WorldObjectType& type, const sf::Vector2f& p, 
	const int& objectTeam)
	: WorldObject(type, p, objectTeam), m_currentAnimationType(AnimationType::Idle){}

//-------------------------------------------------
//this func draw the object
void AnimatedObject::draw(sf::RenderWindow& window) const {
	window.draw(create());
}

//-------------------------------------------------
void AnimatedObject::setAnimationType(const AnimationType& newAnimationType){
	m_lastAnimationType = m_currentAnimationType;
	m_currentAnimationType = newAnimationType;
}

//-------------------------------------------------
AnimationType AnimatedObject::getCurrentAnimationType() const{
	return m_currentAnimationType;
}

//-------------------------------------------------
AnimationType AnimatedObject::getLastAnimationType() const {
	return m_lastAnimationType;
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite AnimatedObject::create() const {
	sf::Sprite result = sf::Sprite(*Animation::instance().
		get_texture(get_type(), m_currentAnimationType, m_lastAnimationType));
	result.setPosition(get_position());
	result.getPosition();
	// 40 = width of texture, 50 = height of texture
	result.setTextureRect(sf::IntRect(40, 0, 40 * get_object_team(), 50));
	return result;
}