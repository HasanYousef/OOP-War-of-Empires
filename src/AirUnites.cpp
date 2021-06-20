#pragma once
#include "AirUnites.h"

AirUnites::AirUnites(const sf::Vector2f& p, const bool& objectTeam, const int& damage)
	: AnimatedObject(p, objectTeam), m_damage(damage), m_hit(std::make_shared<bool>(false)){}

bool AirUnites::getHit(){
	return *m_hit;
}