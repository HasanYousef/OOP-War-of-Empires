#pragma once
#include "MeleeFighter.h"

MeleeFighter::MeleeFighter(const sf::Vector2f& p, const int& objectTeam, const int& health, 
	const int& defaultAttack, const int& defaultGoldWorth)
	: Fighter(p, objectTeam, health, defaultAttack, defaultGoldWorth){
	reSetAnimationObject(FighterType::Tank2);
}

//-------------------------------------------------
void MeleeFighter::attack(const std::shared_ptr<Fighter>& firstEnemy,
	const std::shared_ptr<Castle>& enemyCastle) {
	bool b1 = firstEnemy != NULL && create(0).getGlobalBounds().intersects(firstEnemy->create(0).getGlobalBounds()) && firstEnemy->getHealth() > 0,
		b2 = firstEnemy == NULL && create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds());

	if (b1 || b2){
		if (getAnimationType() == AnimationType::Idle)
			setAnimationType(AnimationType::Attack);
		bool x = m_animation->getCurrFrame() == DAMAGING_FRAME;
		if (getAnimationType() == AnimationType::Attack && x && m_attackClock.getElapsedTime().asSeconds() > 1.5*ANIMATION_SWITCH_TIME) {
			m_attackClock.restart();
			// attacking castle
			if ( !firstEnemy && (create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds())))
				enemyCastle->getDamaged(getDefaultAttack()) ;
			else 
				if (! firstEnemy->getDamaged(getDefaultAttack())) {
					firstEnemy->setAnimationType(AnimationType::Die);
				}
		}
	}
	else if (getAnimationType() == AnimationType::Attack) {
		setAnimationType(AnimationType::Idle);
	}
} 

//-------------------------------------------------
std::shared_ptr<bool> MeleeFighter::fullyDead() const{
	return Fighter::fullyDead();
}

//-------------------------------------------------
//this func draw the object
void MeleeFighter::draw(float f) const {
	Window::instance().getWindow()->draw(create(f));
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite MeleeFighter::create(float f) const {
	auto result = sf::Sprite(*m_animation->getTexture() );
	if (m_animation->update(f) != getAnimationType()) {
		if (m_animation->update(0) == AnimationType::Idle && getAnimationType() == AnimationType::Die && m_animation->getCurrFrame() == 0){
			setFullyDead();
		}
		m_animation->setAnimType(getAnimationType());
	}
	sf::Vector2f temp;
	if(m_animation->getFighterType() == FighterType::Tank2)
		temp = (getAnimationType() == AnimationType::Attack || getAnimationType() == AnimationType::Die) ? 
			sf::Vector2f(0, -30) : sf::Vector2f(0, 0);
	else
		temp = (getAnimationType() == AnimationType::Die) ? sf::Vector2f(0, -30) : sf::Vector2f(0, 0);
	result.setPosition(WorldObject::getPosition() + temp);
	result.scale(0.625f, 0.625f);
	if (WorldObject::getObjectTeam() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
} 