#pragma once
#include "MeleeFighter.h"

MeleeFighter::MeleeFighter(const sf::Vector2f& p, const int& objectTeam, const int& health, 
	const float& defaultAttack, const float& defaultGoldWorth)
	: Fighter(p, objectTeam, health, defaultAttack, defaultGoldWorth), 
	m_animation(std::make_shared<Animation>(FighterType::Tank1)){}


//-------------------------------------------------
void MeleeFighter::attack(const std::shared_ptr<Fighter>& firstEnemy,
	const std::shared_ptr<Castle>& enemyCastle) {
	bool b1 = firstEnemy != NULL && create(0).getGlobalBounds().intersects(firstEnemy->create(0).getGlobalBounds()),
		b2 = firstEnemy == NULL && create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds());

	if (b1 || b2){
		if (getAnimationType() == AnimationType::Idle || getAnimationType() == AnimationType::Walk)
			setAnimationType(AnimationType::Attack);
		bool x = m_animation->getCurrFrame() == DAMAGING_FRAME;
		if (getAnimationType() == AnimationType::Attack && x) {
			// attacking castle
			if (create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds()))
				enemyCastle->getDamaged(getDefaultAttack());
			else 
				firstEnemy->getDamaged(getDefaultAttack());
		}
	}
	else if (getAnimationType() == AnimationType::Attack) {
		setAnimationType(AnimationType::Idle);
	}
}

//------------------------------------------------
bool MeleeFighter::fullyDead() {
	if (getHealth() <= 0) {
		setAnimationType(AnimationType::Die);
		if (m_animation->update(0) == AnimationType::Idle)
			return true;
	}
	return  false;
}

//-------------------------------------------------
//this func draw the object
void MeleeFighter::draw(float f) const {
	Window::instance().get_window()->draw(create(f));
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite MeleeFighter::create(float f) const {
	auto result = sf::Sprite(*m_animation->get_texture() );
	if(m_animation->update(f) != getAnimationType())
		m_animation->set_anim_type(getAnimationType());
	result.setPosition(WorldObject::get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
} 