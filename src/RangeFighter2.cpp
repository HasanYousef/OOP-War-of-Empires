#pragma once
#include "RangeFighter2.h"

RangeFighter2::RangeFighter2(const sf::Vector2f& p, const int& objectTeam, const int& health,
	const int& defaultAttack, const int& defaultGoldWorth)
	: RangeFighter(p, objectTeam, health, defaultAttack, defaultGoldWorth) {
	AnimatedObject::reSetAnimationObject(FighterType::Shooter2);
}