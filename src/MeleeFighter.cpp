#pragma once
#include "MeleeFighter.h"

MeleeFighter::MeleeFighter(const sf::Vector2f& p, const int& objectTeam, const int& health, 
	const float& defaultAttack, const float& defaultGoldWorth)
	: Fighter(p, objectTeam, health, defaultAttack, defaultGoldWorth), 
	m_animation(std::make_shared<Animation>(FighterType::Shooter2)){}


//-------------------------------------------------
//this func draw the object
void MeleeFighter::draw(float f) const {
	Window::instance().get_window()->draw(create(f));
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite MeleeFighter::create(float f) const {
	//m_animation->set_anim_type(getAnimationType());
	auto result = sf::Sprite(*m_animation->get_texture() );
	m_animation->update(f);
	result.setPosition(WorldObject::get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
} 