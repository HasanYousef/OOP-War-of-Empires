#pragma once
#include "KiteBalloon.h"

KiteBalloon::KiteBalloon(const sf::Vector2f& p, const bool& objectTeam)
	: AnimatedObject(p - sf::Vector2f(200, 0), objectTeam),
	m_animation(std::make_shared<KiteBalloonAnimation>()),
	m_movementClock(std::make_shared<sf::Clock>()),
	m_sendBombClock(std::make_shared<sf::Clock>()) {
	srand((unsigned)time(NULL));
}

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
std::shared_ptr<AirUnites> KiteBalloon::dropBomb() {
	double rand1 = (double)(rand() % 20) / (double)10;
	if ((double)(m_sendBombClock->getElapsedTime().asSeconds()) > (rand1 + (double)0.5)) {
		m_sendBombClock->restart();
		auto bomb = std::make_shared<AirBomb>(sf::Vector2f(m_position.x + (create(0).getGlobalBounds().width / 2)*(m_objectTeam ? 1 : -1),
															m_position.y + (create(0).getGlobalBounds().height) * 0.8), 
			m_objectTeam, BOMB_DAMAGE * Levels::instance().get_kite_level(m_objectTeam), Levels::instance().get_kite_level(m_objectTeam));
		return bomb;
	}
	return NULL;
}

//-------------------------------------------------
void KiteBalloon::addLevel() {
	Levels::instance().add_kite_level(m_objectTeam);
}

//-------------------------------------------------
//this func draw the object
void KiteBalloon::draw(float f) const {
	Window::instance().get_window()->draw(create(f));
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite KiteBalloon::create(float f) const {
	m_animation->set_kite_level(Levels::instance().get_kite_level(m_objectTeam));

	auto result = sf::Sprite(*(m_animation->get_texture()));

	m_animation->update(f);

	result.setPosition(WorldObject::get_position());
	result.setScale(200.0f / result.getLocalBounds().width,
		200.0f / result.getLocalBounds().height);
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}