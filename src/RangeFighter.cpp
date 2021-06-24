#pragma once
#include "RangeFighter.h"

RangeFighter::RangeFighter(const sf::Vector2f& p, const int& objectTeam, const int& health,
	const int& defaultAttack, const int& defaultGoldWorth)
	: Fighter(p, objectTeam, health, defaultAttack, defaultGoldWorth), 
	m_movementClock(std::make_shared<sf::Clock>()),
	m_gunFire(std::make_shared<GunFire>(p + sf::Vector2f(80,20), objectTeam)) {
	reSetAnimationObject(FighterType::Shooter1);
}


//-------------------------------------------------
void RangeFighter::attack(const std::shared_ptr<Fighter>& firstEnemy,
	const std::shared_ptr<Castle>& enemyCastle) {
	bool b1 = firstEnemy != NULL && 
		( getDistance(create(0), firstEnemy->create(0)) < 
			ATTACK_RANGE + ATTACK_RANGE * (Levels::instance().getLevel(WorldObject::m_objectTeam,int(m_animation->getFighterType()))/3) ||
			create(0).getGlobalBounds().intersects(firstEnemy->create(0).getGlobalBounds())) &&
		firstEnemy->getHealth() > 0,
		b2 = firstEnemy == NULL && 
		( getDistance(create(0), enemyCastle->create(0)) < 
			ATTACK_RANGE + ATTACK_RANGE * (Levels::instance().getLevel(WorldObject::m_objectTeam, int(m_animation->getFighterType()))/3) ||
			create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds()));

	if (b1 || b2) {
		if (getAnimationType() == AnimationType::Idle)
			setAnimationType(AnimationType::Idle);

		bool x = m_animation->getCurrFrame() == RANGE_DAMAGING_FRAME;
		if (getAnimationType() == AnimationType::Idle&& x && m_attackClock.getElapsedTime().asSeconds() > 1.5*ANIMATION_SWITCH_TIME) {
			m_attackClock.restart();
			
			if (firstEnemy.get() == NULL && (getDistance(create(0), enemyCastle->create(0)) < 
				ATTACK_RANGE + ATTACK_RANGE * (Levels::instance().getLevel(WorldObject::m_objectTeam, int(m_animation->getFighterType()))/3) ||
				create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds()))) {
				// activate gunshot
				m_gunFire->activate();
				// attacking castle
				enemyCastle->getDamaged(getDefaultAttack());
			}
			else {
				if(firstEnemy != NULL && firstEnemy->getDamaged(0))
					// activate gunshot
					m_gunFire->activate();
				if (firstEnemy != NULL && !firstEnemy->getDamaged(getDefaultAttack())) {
					firstEnemy->setAnimationType(AnimationType::Die);
				}
			}
		}
	}
	else if (getAnimationType() == AnimationType::Idle/*AnimationType::Attack*/) {
		setAnimationType(AnimationType::Idle);
	}
}

//-------------------------------------------------
void RangeFighter::move(const std::shared_ptr<Fighter>& nextAlly,
	const std::shared_ptr<Fighter>& firstEnemy,
	const std::shared_ptr<Castle>& enemyCastle) {

	if ((nextAlly == NULL || !create(0).getGlobalBounds().intersects(nextAlly->create(0).getGlobalBounds())) &&
		(firstEnemy == NULL || !create(0).getGlobalBounds().intersects(firstEnemy->create(0).getGlobalBounds())) &&
		!create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds())) {
		if (getAnimationType() == AnimationType::Idle &&
			(nextAlly == NULL || nextAlly->getAnimationObject()->update(0) != AnimationType::Idle))
			setAnimationType(AnimationType::Walk);
		if (getAnimationType() == AnimationType::Walk && m_movementClock->getElapsedTime().asMilliseconds() > FIGHTER_MOVEMENT_SPEED) {
			m_movementClock->restart();

			// moving enemy
			sf::Vector2f x = sf::Vector2f(
				WorldObject::getPosition().x + ((WorldObject::getObjectTeam()) ? 1 : -1),
				WorldObject::getPosition().y);

			WorldObject::setPosition(x);
			m_gunFire->setPosition(x + sf::Vector2f(WorldObject::m_objectTeam ? 75*0.625: -75 * 0.625,5));
		}
	}
	else if (getAnimationType() == AnimationType::Walk &&
		(nextAlly == NULL || nextAlly->getAnimationObject()->update(0) != AnimationType::Walk)) {
		setAnimationType(AnimationType::Idle);
	}
}

//-------------------------------------------------
std::shared_ptr<bool> RangeFighter::fullyDead() const {
	return Fighter::fullyDead();
}

//-------------------------------------------------
std::shared_ptr<GunFire> RangeFighter::getGunFire() const {
	return m_gunFire;
}

//-------------------------------------------------
std::shared_ptr<sf::Clock> RangeFighter::getMovementClock() const {
	return m_movementClock;
}


//-------------------------------------------------
//this func draw the object
void RangeFighter::draw(float f) const {
	Window::instance().getWindow()->draw(create(f));
	m_gunFire->draw(f*5);
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite RangeFighter::create(float f) const {
	auto result = sf::Sprite(*m_animation->getTexture());
	if (m_animation->update(f) != getAnimationType()) {
		if (m_animation->update(0) == AnimationType::Idle && getAnimationType() == AnimationType::Die && m_animation->getCurrFrame() == 0) {
			setFullyDead();
		}
		m_animation->setAnimType(getAnimationType());
	}
	sf::Vector2f temp = (getAnimationType() == AnimationType::Die) ? sf::Vector2f(0, -40) : sf::Vector2f(0, 0);
	result.setPosition(WorldObject::getPosition() + temp);
	result.scale(0.625f, 0.625f);
	if (WorldObject::getObjectTeam() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}

