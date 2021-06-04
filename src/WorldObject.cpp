#pragma once
#include "WorldObject.h"

//-------------------------------------------------
WorldObject::WorldObject() {}

WorldObject::WorldObject(const WorldObjectType& type, const sf::Vector2f& p) 
	: m_objectType(type), m_position(p), m_objectTeam(1) {}

WorldObject::WorldObject(const WorldObjectType& type, const sf::Vector2f& p, const int& objectTeam)
	: m_objectType(type), m_position(p), m_objectTeam(objectTeam) {}

//-------------------------------------------------
sf::Vector2f WorldObject::get_position() const {
	return m_position;
}

//-------------------------------------------------
void WorldObject::set_position(const sf::Vector2f& position) {
	m_position = position;
}

//-------------------------------------------------
//this func draw the object
void WorldObject::draw(sf::RenderWindow& window) const {
	window.draw(create());
}

//-------------------------------------------------
//we get the type of the object(player,enemy....)
const WorldObjectType& WorldObject::get_type() const {
	return m_objectType;
}

//-------------------------------------------------
void WorldObject::set_type(const WorldObjectType& newObjectType) {
	m_objectType = newObjectType;
}

//-------------------------------------------------
int WorldObject::get_object_team() const {
	return m_objectTeam;
}

//-------------------------------------------------
//we creat the texture that we want to print it 
sf::Sprite WorldObject::create() const {
	sf::Sprite result = sf::Sprite(*Textures::instance().
		get_texture(m_objectType));
	result.setPosition(m_position);
	result.getPosition();
	// 40 = width of texture, 50 = height of texture
	result.setTextureRect(sf::IntRect(40, 0, 40 * m_objectTeam, 50));
	return result;
}
