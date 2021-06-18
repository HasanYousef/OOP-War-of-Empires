#pragma once
#include "MeleeFighter2.h"

MeleeFighter2::MeleeFighter2(const sf::Vector2f& p, const int& objectTeam, const int& health,
	const int& defaultAttack, const int& defaultGoldWorth)
	: MeleeFighter(p, objectTeam, health, defaultAttack, defaultGoldWorth) {
	reSetAnimationObject(FighterType::Tank2);
}
