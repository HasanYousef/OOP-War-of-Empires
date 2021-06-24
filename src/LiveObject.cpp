#pragma once
#include "LiveObject.h"

//-------------------------------------------------
LiveObject::LiveObject(const sf::Vector2f& p,
	const int& objectTeam, const int& health)
	: WorldObject(p, objectTeam), m_health(health) {}

//-------------------------------------------------
int LiveObject::getHealth() const {
	return m_health;
}

//-------------------------------------------------
void LiveObject::setHealth(const int& newHealth){
	m_health = newHealth;
}

//-------------------------------------------------
bool LiveObject::getDamaged(const int& damage) {
	m_health -= damage;
	if (m_health <= 0)
		return DEAD;
	return ALIVE;
}
