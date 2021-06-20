#pragma once
#include "AirUnites.h"

AirUnites::AirUnites(const sf::Vector2f& p, const bool& objectTeam, const int& damage)
	: AnimatedObject(p, objectTeam), m_damage(damage){}

bool AirUnites::getHit(){
	return m_hit;
}

bool AirUnites::collied(std::list <std::shared_ptr <Fighter>>& enemies, const sf::Vector2f& floorPosition) {
	int fighternum = 0;
	for (auto fighter = enemies.begin(); fighter != enemies.end(); ++fighter) {
		auto enemy = fighter->get()->create(0);
		auto pos = enemy.getPosition();
		enemy.setPosition(pos.x, pos.y + enemy.getGlobalBounds().height / 4);
		if (create(0).getGlobalBounds().intersects(enemy.getGlobalBounds())) {
			if (!(*fighter)->getDamaged(m_damage))
				(*fighter)->setAnimationType(AnimationType::Die);
			m_hit = true;
			return true;
		}
	}
	if (create(0).getPosition().y + create(0).getGlobalBounds().height >= floorPosition.y) {
		m_hit = true;
		return true;
	}
	m_hit = false;
	return false;
}