#pragma once
#include "LiveObject.h"

//-------------------------------------------------
LiveObject::LiveObject(const sf::Vector2f& p,
	const int& objectTeam, const int& health)
	: WorldObject(p, objectTeam), m_health(health) {}

//-------------------------------------------------
int LiveObject::getHealth()const {
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

//-------------------------------------------------
//we creat the texture that we want to print it 
/*
sf::Sprite LiveObject::create() const {
	sf::Sprite result = sf::Sprite(*Textures::instance().
		get_texture(get_type()));
	result.setPosition(get_position());
	result.getPosition();
	// 40 = width of texture, 50 = height of texture
	result.setTextureRect(sf::IntRect(40, 0, 40 * get_object_team(), 50));
	return result;
} */