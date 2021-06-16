#pragma once
#include "AnimatedObject.h"

//-------------------------------------------------
AnimatedObject::AnimatedObject(const sf::Vector2f& p) 
	: WorldObject(p), m_animationType(AnimationType::Walk),
	m_animation(std::make_shared<Animation>(FighterType::Tank1)) {}

AnimatedObject::AnimatedObject(const sf::Vector2f& p, const bool& objectTeam)
	: WorldObject(p, objectTeam), m_animationType(AnimationType::Walk),
	m_animation(std::make_shared<Animation>(FighterType::Tank1)) {}

AnimatedObject::AnimatedObject(const sf::Vector2f& p, const bool& objectTeam, const AnimationType& animationType) 
	: WorldObject(p, objectTeam), m_animationType(animationType),
	m_animation(std::make_shared<Animation>(animationType)) {}
	

//-------------------------------------------------
void AnimatedObject::setAnimationType(const AnimationType& newAnimationType){
	m_animationType = newAnimationType;
}

//-------------------------------------------------
AnimationType AnimatedObject::getAnimationType() const{
	return m_animationType;
}

//-------------------------------------------------
std::shared_ptr <Animation> AnimatedObject::getAnimationObject() const{
	return m_animation;
}

//-------------------------------------------------

void AnimatedObject::reSetAnimationObject(const FighterType& newFighterType) {
	m_animation = std::make_shared<Animation>(newFighterType);
}


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