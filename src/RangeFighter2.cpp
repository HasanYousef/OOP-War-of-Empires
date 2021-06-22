#pragma once
#include "RangeFighter2.h"

RangeFighter2::RangeFighter2(const sf::Vector2f& p, const int& objectTeam)
	: RangeFighter(p, objectTeam, RANGE_1_HEALTH* (Levels::instance().get_level(objectTeam, int(FighterType::Shooter2)))
		, RANGE_2_DAMAGE* (Levels::instance().get_level(objectTeam, int(FighterType::Shooter2))),
		RANGE_2_WORTH* (Levels::instance().get_level(objectTeam, int(FighterType::Shooter2)))) {
	reSetAnimationObject(FighterType::Shooter2);
}

void RangeFighter2::addLevel() {
	Levels::instance().add_level(WorldObject::m_objectTeam, int(FighterType::Shooter2));
}