#pragma once
#include "WorldObject.h"

//-------------------------------------------------
// constructors
WorldObject::WorldObject(const sf::Vector2f& p) 
	: m_position(p), m_objectTeam(true) {}

WorldObject::WorldObject(const sf::Vector2f& p, const bool& objectTeam)
	: m_position(p), m_objectTeam(objectTeam) {}

//-------------------------------------------------
sf::Vector2f WorldObject::getPosition() const {
	return m_position;
}

//-------------------------------------------------
void WorldObject::setPosition(const sf::Vector2f& position) {
	m_position = position;
}

//-------------------------------------------------
bool WorldObject::getObjectTeam() const {
	return m_objectTeam;
}

//-------------------------------------------------
// draw object texture
void WorldObject::draw(float delta) const {
	Window::instance().getWindow()->draw(create(delta));
}

//-------------------------------------------------
// calculate 2d distance = sqrt(delta(x)^2 + delta(y)^2) 
float getDistance(const sf::Sprite& right, const sf::Sprite& left) {
	float distance = (std::abs(
		std::sqrt(((right.getPosition().x - left.getPosition().x) * (right.getPosition().x - left.getPosition().x))
			+ ((right.getPosition().y - left.getPosition().y) * (right.getPosition().y - left.getPosition().y)))));

	return distance;
}