#pragma once
#include "MeleeFighter1.h"

MeleeFighter1::MeleeFighter1(const sf::Vector2f& p, const int& objectTeam)
	: MeleeFighter(p, objectTeam, MELEE_1_HEALTH* (Levels::instance().getLevel(objectTeam, int(FighterType::Tank1)))
		, MELEE_1_DAMAGE*(Levels::instance().getLevel(objectTeam, int(FighterType::Tank1))),
		MELEE_1_WORTH* (Levels::instance().getLevel(objectTeam, int(FighterType::Tank1)))) {
	reSetAnimationObject(FighterType::Tank1);
}

void MeleeFighter1::addLevel() {
	Levels::instance().addLevel(WorldObject::m_objectTeam, int(FighterType::Tank1));
}