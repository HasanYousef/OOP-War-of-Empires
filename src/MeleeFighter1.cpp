#pragma once
#include "MeleeFighter1.h"

MeleeFighter1::MeleeFighter1(const sf::Vector2f& p, const int& objectTeam, const int& health,
	const int& defaultAttack, const int& defaultGoldWorth)
	: MeleeFighter(p, objectTeam, health, defaultAttack, defaultGoldWorth) {
	AnimatedObject::reSetAnimationObject(FighterType::Tank1);
}
