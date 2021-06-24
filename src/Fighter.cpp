#pragma once
#include "Fighter.h"

Fighter::Fighter(const sf::Vector2f& p, const bool& objectTeam, const int& health,
	const int& defaultAttack, const int& defaultGoldWorth)
	: AnimatedObject(p, objectTeam), LiveObject(p, objectTeam, health)
	, m_defaultAttack(defaultAttack), m_defaultGoldWorth(defaultGoldWorth),
	m_lastMovement(), m_fullyDead(std::make_shared<bool>(false)),
	m_animation(std::make_shared<FighterAnimation>(FighterType::Tank1)),
	m_animationType(AnimationType::Walk) {}

const int& Fighter::getDefaultAttack() const {
	return m_defaultAttack;
}

int Fighter::getGoldWorth() const {
	return m_defaultGoldWorth;
}

void Fighter::setFullyDead() const {
	*m_fullyDead = true;
}

std::shared_ptr<bool> Fighter::fullyDead() const {
	return m_fullyDead;
}


//-------------------------------------------------
std::shared_ptr <FighterAnimation> Fighter::getAnimationObject() const {
	return m_animation;
}

//-------------------------------------------------

void Fighter::reSetAnimationObject(const FighterType& newFighterType) {
	m_animation = std::make_shared<FighterAnimation>(newFighterType);
}


//-------------------------------------------------
void Fighter::setAnimationType(const AnimationType& newAnimationType) {
	m_animationType = newAnimationType;
}

//-------------------------------------------------
AnimationType Fighter::getAnimationType() const {
	return m_animationType;
}


//-------------------------------------------------
void Fighter::move(const std::shared_ptr<Fighter>& nextAlly,
	const std::shared_ptr<Fighter>& firstEnemy,
	const std::shared_ptr<Castle>& enemyCastle) {
	if ((nextAlly == NULL || !create(0).getGlobalBounds().intersects(nextAlly->create(0).getGlobalBounds())) &&
		(firstEnemy == NULL || !create(0).getGlobalBounds().intersects(firstEnemy->create(0).getGlobalBounds())) &&
		!create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds())) {
		if (getAnimationType() == AnimationType::Idle &&
			(nextAlly == NULL || nextAlly->getAnimationObject()->update(0) != AnimationType::Idle))
			setAnimationType(AnimationType::Walk);
		if (getAnimationType() == AnimationType::Walk && m_clock.getElapsedTime().asMilliseconds() > FIGHTER_MOVEMENT_SPEED) {
			m_clock.restart();
			// moving enemy
			sf::Vector2f x = sf::Vector2f(
				WorldObject::getPosition().x + ((WorldObject::getObjectTeam()) ? 1 : -1),
				WorldObject::getPosition().y);

			WorldObject::setPosition(x);
		}
	}
	else if (getAnimationType() == AnimationType::Walk &&
		(nextAlly == NULL || nextAlly->getAnimationObject()->update(0) != AnimationType::Walk)) {
		setAnimationType(AnimationType::Idle);
	}
}