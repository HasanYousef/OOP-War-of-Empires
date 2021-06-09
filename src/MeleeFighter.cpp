#pragma once
#include "MeleeFighter.h"

MeleeFighter::MeleeFighter(const sf::Vector2f& p, const int& objectTeam, const int& health, 
	const float& defaultAttack, const float& defaultGoldWorth)
	: Fighter(p, objectTeam, health, defaultAttack, defaultGoldWorth), 
	m_animation(std::make_shared<Animation>(FighterType::Melee)){}

//-------------------------------------------------
void MeleeFighter::move(const std::shared_ptr<Fighter> nextAlly, 
	const std::shared_ptr<Fighter> firstEnemy, 
	const std::shared_ptr<Castle> enemyCastle) {
	if (!create(0).getGlobalBounds().intersects(nextAlly->create(0).getGlobalBounds()) &&
		!create(0).getGlobalBounds().intersects(firstEnemy->create(0).getGlobalBounds()) &&
		!create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds()) ) {
		if (getAnimationType() == AnimationType::Idle)
			setAnimationType(AnimationType::Walk);
		if (getAnimationType() == AnimationType::Walk /*&& check clock*/)
			// moving enemy
			WorldObject::set_position(sf::Vector2f(
				WorldObject::get_position().x + ((WorldObject::get_object_team()) ? 1 : -1),
				WorldObject::get_position().y));
	}

}

//-------------------------------------------------
//this func draw the object
void MeleeFighter::draw(float f) const {
	Window::instance().get_window()->draw(create(f));
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite MeleeFighter::create(float f) const {
	//m_animation->set_anim_type(getAnimationType());
	auto result = sf::Sprite( * m_animation->get_texture() );
	m_animation->update(f);
	result.setPosition(LiveObject::get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
} 