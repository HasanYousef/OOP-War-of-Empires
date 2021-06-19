#pragma once
#include "KiteBalloon.h"

KiteBalloon::KiteBalloon(const sf::Vector2f& p, const bool& objectTeam)
	: AnimatedObject(p, objectTeam),
	m_animation(std::make_shared<KiteBalloonAnimation>()),
	m_movementClock(std::make_shared<sf::Clock>()),
	m_sendBombClock(std::make_shared<sf::Clock>()) {}

//-------------------------------------------------
void KiteBalloon::move(){
	if (m_movementClock->getElapsedTime().asMilliseconds() > FIGHTER_MOVEMENT_SPEED*0.5f) {
		m_movementClock->restart();
		// moving enemy
		sf::Vector2f x = sf::Vector2f(
			WorldObject::get_position().x + ((WorldObject::get_object_team()) ? 1 : -1),
			WorldObject::get_position().y);

		WorldObject::set_position(x);
	}
}

//-------------------------------------------------
//this func draw the object
void KiteBalloon::draw(float f) const {
	Window::instance().get_window()->draw(create(f));
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite KiteBalloon::create(float f) const {
	auto result = sf::Sprite(*(m_animation->get_texture()));

	m_animation->update(f);

	result.setPosition(WorldObject::get_position());
	result.setScale(200.0f / result.getLocalBounds().width,
		200.0f / result.getLocalBounds().height);
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}