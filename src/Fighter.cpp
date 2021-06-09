#pragma once
#include "Fighter.h"

Fighter::Fighter(const sf::Vector2f& p, const bool& objectTeam, const int& health, 
	const float& defaultAttack, const float& defaultGoldWorth)
	: AnimatedObject(p, objectTeam), LiveObject(p, objectTeam, health)
	, m_level(1), m_defaultAttack(defaultAttack), m_defaultGoldWorth(defaultGoldWorth){
	// applying speed limits ------------------------------------------
	/*
	if (movementSpeed > MAX_MOVEMENT_SPEED &&
		movementSpeed < MIN_MOVEMENT_SPEED)
		m_movementSpeed = movementSpeed;
	else
		m_movementSpeed = (MIN_MOVEMENT_SPEED + MAX_MOVEMENT_SPEED) / 2;
	if (movementSpeed > MAX_ATTACK_SPEED &&
		movementSpeed < MIN_ATTACK_SPEED)
		m_attackSpeed = attackSpeed;
	else
		m_attackSpeed = (MIN_ATTACK_SPEED + MAX_ATTACK_SPEED) / 2;
		*/
	//-----------------------------------------------------------------
}

void Fighter::addLevel() {
	m_level++;
}

const float& Fighter::getLevel() const {
	return m_level;
}

const float& Fighter::getDefaultAttack() const {
	return m_defaultAttack;
}