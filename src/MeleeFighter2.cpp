#pragma once
#include "MeleeFighter2.h"

MeleeFighter2::MeleeFighter2(const sf::Vector2f& p, const int& objectTeam)
	: MeleeFighter(p, objectTeam, MELEE_2_HEALTH* (Levels::instance().get_level(objectTeam, int(FighterType::Tank2)))
		, MELEE_2_DAMAGE* (Levels::instance().get_level(objectTeam, int(FighterType::Tank2))),
		MELEE_2_WORTH* (Levels::instance().get_level(objectTeam, int(FighterType::Tank2)))) {
	reSetAnimationObject(FighterType::Tank2);
}

void MeleeFighter2::addLevel() {
	Levels::instance().add_level(WorldObject::m_objectTeam, int(FighterType::Tank2));
}