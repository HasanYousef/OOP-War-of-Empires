#pragma once
#include "RangeFighter3.h"

RangeFighter3::RangeFighter3(const sf::Vector2f& p, const int& objectTeam)
	: RangeFighter(p, objectTeam, RANGE_3_HEALTH* (Levels::instance().getLevel(objectTeam, int(FighterType::Shooter3)))
		, RANGE_3_DAMAGE* (Levels::instance().getLevel(objectTeam, int(FighterType::Shooter3))),
		RANGE_3_WORTH* (Levels::instance().getLevel(objectTeam, int(FighterType::Shooter3)))) {
	reSetAnimationObject(FighterType::Shooter3);
}

//-------------------------------------------------
void RangeFighter3::move(const std::shared_ptr<Fighter>& nextAlly,
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
			getGunFire()->setPosition(x + sf::Vector2f(WorldObject::m_objectTeam ? 85*0.625:-85 * 0.625, 30 * 0.625));
		}
	}
	else if (getAnimationType() == AnimationType::Walk &&
		(nextAlly == NULL || nextAlly->getAnimationObject()->update(0) != AnimationType::Walk)) {
		setAnimationType(AnimationType::Idle);
	}
}

void RangeFighter3::addLevel() {
	Levels::instance().addLevel(WorldObject::m_objectTeam, int(FighterType::Shooter3));
}