#pragma once
#include "RangeFighter1.h"

RangeFighter1::RangeFighter1(const sf::Vector2f& p, const int& objectTeam, const int& health,
	const int& defaultAttack, const int& defaultGoldWorth)
	: RangeFighter(p, objectTeam, health, defaultAttack, defaultGoldWorth) {
	reSetAnimationObject(FighterType::Shooter1);
}