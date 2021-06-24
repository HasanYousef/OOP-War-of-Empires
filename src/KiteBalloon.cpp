#pragma once
#include "KiteBalloon.h"

KiteBalloon::KiteBalloon(const sf::Vector2f& p, const bool& objectTeam)
	: AnimatedObject(p + sf::Vector2f(objectTeam ? -150 : 150, 0), objectTeam),
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
			WorldObject::getPosition().x + ((WorldObject::getObjectTeam()) ? 1 : -1),
			WorldObject::getPosition().y);

		WorldObject::setPosition(x);
	}
}

//-------------------------------------------------
std::shared_ptr<AirUnites> KiteBalloon::dropBomb() {
	double rand1 = (double)(rand() % 5) / (double)10;
	if ((double)(m_sendBombClock->getElapsedTime().asSeconds()) > (rand1+(double)0.5)) {
		m_sendBombClock->restart();
		auto bomb = std::make_shared<AirBomb>(sf::Vector2f(m_position.x + (create(0).getGlobalBounds().width / 2)*(m_objectTeam ? 1 : -1),
															m_position.y + (create(0).getGlobalBounds().height) * 0.8), 
			m_objectTeam, BOMB_DAMAGE * Levels::instance().getKiteLevel(m_objectTeam), Levels::instance().getKiteLevel(m_objectTeam));
		return bomb;
	}
	return NULL;
}

//-------------------------------------------------
void KiteBalloon::addLevel() {
	Levels::instance().addKiteLevel(m_objectTeam);
}

//-------------------------------------------------
//this func draw the object
void KiteBalloon::draw(float f) const {
	Window::instance().getWindow()->draw(create(f));
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite KiteBalloon::create(float f) const {
	m_animation->setKiteLevel(Levels::instance().getKiteLevel(m_objectTeam));

	auto result = sf::Sprite(*(m_animation->getTexture()));

	m_animation->update(f);

	result.setPosition(WorldObject::getPosition());
	result.setScale(200.0f / result.getLocalBounds().width,
		200.0f / result.getLocalBounds().height);
	if (WorldObject::getObjectTeam() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}