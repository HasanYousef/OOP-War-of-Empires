#pragma once
#include "RangeFighter1.h"

RangeFighter1::RangeFighter1(const sf::Vector2f& p, const int& objectTeam)
	: RangeFighter(p, objectTeam, RANGE_1_HEALTH* (Levels::instance().getLevel(objectTeam, int(FighterType::Shooter1)))
		, RANGE_1_DAMAGE* (Levels::instance().getLevel(objectTeam, int(FighterType::Shooter1))),
		RANGE_1_WORTH* (Levels::instance().getLevel(objectTeam, int(FighterType::Shooter1)))) {
	reSetAnimationObject(FighterType::Shooter1);
}

void RangeFighter1::addLevel() {
	Levels::instance().addLevel(WorldObject::m_objectTeam, int(FighterType::Shooter1));
}