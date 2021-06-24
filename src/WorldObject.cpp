#pragma once
#include "WorldObject.h"

//-------------------------------------------------
WorldObject::WorldObject(const sf::Vector2f& p) 
	: m_position(p), m_objectTeam(true) {}

WorldObject::WorldObject(const sf::Vector2f& p, const bool& objectTeam)
	: m_position(p), m_objectTeam(objectTeam) {}

//-------------------------------------------------
sf::Vector2f WorldObject::get_position() const {
	return m_position;
}

//-------------------------------------------------
void WorldObject::set_position(const sf::Vector2f& position) {
	m_position = position;
}

//-------------------------------------------------
bool WorldObject::get_object_team() const {
	return m_objectTeam;
}

//-------------------------------------------------
//we creat the texture that we want to print it 
/*
sf::Sprite WorldObject::create() const {
	sf::Sprite result = sf::Sprite(*Textures::instance().
		get_texture(m_objectType));
	result.setPosition(m_position);
	result.getPosition();
	// 40 = width of texture, 50 = height of texture
	result.setTextureRect(sf::IntRect(40, 0, 40 * m_objectTeam, 50));
	return result;
}
*/


void WorldObject::draw(float delta) const {
	Window::instance().get_window()->draw(create(delta));
}

float getDistance(const sf::Sprite& right, const sf::Sprite& left) {
	float distance = (std::abs(
		std::sqrt(((right.getPosition().x - left.getPosition().x) * (right.getPosition().x - left.getPosition().x))
			+ ((right.getPosition().y - left.getPosition().y) * (right.getPosition().y - left.getPosition().y)))));

	return distance;
}