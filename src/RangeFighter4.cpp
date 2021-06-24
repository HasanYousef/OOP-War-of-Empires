#pragma once
#include "RangeFighter4.h"

RangeFighter4::RangeFighter4(const sf::Vector2f& p, const int& objectTeam)
	: RangeFighter(p + sf::Vector2f(0, -30), objectTeam, RANGE_4_HEALTH* (Levels::instance().getLevel(objectTeam, int(FighterType::Tank3)))
		, RANGE_4_DAMAGE* (Levels::instance().getLevel(objectTeam, int(FighterType::Tank3))),
		RANGE_4_WORTH* (Levels::instance().getLevel(objectTeam, int(FighterType::Tank3)))) {
	reSetAnimationObject(FighterType::Tank3);
}

//-------------------------------------------------
void RangeFighter4::move(const std::shared_ptr<Fighter>& nextAlly,
	const std::shared_ptr<Fighter>& firstEnemy,
	const std::shared_ptr<Castle>& enemyCastle) {

	if ((nextAlly == NULL || !create(0).getGlobalBounds().intersects(nextAlly->create(0).getGlobalBounds())) &&
		(firstEnemy == NULL || !create(0).getGlobalBounds().intersects(firstEnemy->create(0).getGlobalBounds())) &&
		!create(0).getGlobalBounds().intersects(enemyCastle->create(0).getGlobalBounds())) {
		if (getAnimationType() == AnimationType::Idle &&
			(nextAlly == NULL || nextAlly->getAnimationObject()->update(0) != AnimationType::Idle))
			setAnimationType(AnimationType::Walk);
		if (getAnimationType() == AnimationType::Walk && getMovementClock()->getElapsedTime().asMilliseconds() > FIGHTER_MOVEMENT_SPEED) {
			getMovementClock()->restart();

			// moving enemy
			sf::Vector2f x = sf::Vector2f(
				WorldObject::getPosition().x + ((WorldObject::getObjectTeam()) ? 1 : -1),
				WorldObject::getPosition().y);

			WorldObject::setPosition(x);
			getGunFire()->setPosition(x + sf::Vector2f((WorldObject::getObjectTeam() == LEFT_TEAM) ? 150 * 0.625 : -150 * 0.625, 52 * 0.625));
		}
	}
	else if (getAnimationType() == AnimationType::Walk &&
		(nextAlly == NULL || nextAlly->getAnimationObject()->update(0) != AnimationType::Walk)) {
		setAnimationType(AnimationType::Idle);
	}
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite RangeFighter4::create(float f) const {
	auto lastAimation = m_animation->update(0);
	auto result = sf::Sprite(*m_animation->getTexture());
	if (m_animation->update(f) != getAnimationType()) {
		if (getHealth() <= 0 && m_animation->update(0) == AnimationType::Idle && lastAimation == AnimationType::Die && m_animation->getCurrFrame() == 0) {
			setFullyDead();
		}
		m_animation->setAnimType(getAnimationType());
	}
	result.setPosition(WorldObject::getPosition());
	result.setScale(200.0f / result.getLocalBounds().width,
		200.0f / result.getLocalBounds().height);
	result.scale(0.625f, 0.625f);
	if (WorldObject::getObjectTeam() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}

void RangeFighter4::addLevel() {
	Levels::instance().addLevel(WorldObject::m_objectTeam, int(FighterType::Tank3));
}