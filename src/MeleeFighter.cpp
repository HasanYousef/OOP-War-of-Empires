#pragma once
#include "MeleeFighter.h"

MeleeFighter::MeleeFighter(const sf::Vector2f& p, const int& objectTeam, const int& health, 
	const float& defaultAttack, const float& defaultGoldWorth)
	: Fighter(p, objectTeam, health, defaultAttack, defaultGoldWorth), m_animation(std::make_shared<Animation>(FighterType::Melee)){
}

//-------------------------------------------------
//this func draw the object
void MeleeFighter::draw(sf::RenderWindow& window) const {
	window.draw(create());
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite MeleeFighter::create() const {
	m_animation->set_anim_type(getAnimationType());
	auto result = sf::Sprite( * m_animation->get_texture() );
	m_animation->update(ANIMATION_SWITCH_TIME);
	result.setPosition(LiveObject::get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
} 