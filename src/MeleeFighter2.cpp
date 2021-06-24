#pragma once
#include "MeleeFighter2.h"

MeleeFighter2::MeleeFighter2(const sf::Vector2f& p, const int& objectTeam)
	: MeleeFighter(p, objectTeam, MELEE_2_HEALTH* (Levels::instance().getLevel(objectTeam, int(FighterType::Tank2)))
		, MELEE_2_DAMAGE* (Levels::instance().getLevel(objectTeam, int(FighterType::Tank2))),
		MELEE_2_WORTH* (Levels::instance().getLevel(objectTeam, int(FighterType::Tank2)))) {
	reSetAnimationObject(FighterType::Tank2);
}

void MeleeFighter2::addLevel() {
	Levels::instance().addLevel(WorldObject::m_objectTeam, int(FighterType::Tank2));
}