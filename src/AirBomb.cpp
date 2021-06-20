#pragma once
#include "AirBomb.h"

AirBomb::AirBomb(const sf::Vector2f& p, const bool& objectTeam, const int& damage)
	: AirUnites(p, objectTeam, damage),
	m_animation(std::make_shared<AirBombAnimation>()),
	m_movementClock(std::make_shared<sf::Clock>()),
	m_gravityClock(std::make_shared<sf::Clock>()){}

//-------------------------------------------------
void AirBomb::move() {
	if (m_movementClock->getElapsedTime().asMilliseconds() > m_xMovementSpeed) {
		m_movementClock->restart();
		// moving enemy
		double gravity = std::sqrt( ( (m_gravityClock->getElapsedTime().asSeconds()) * 
			(m_gravityClock->getElapsedTime().asSeconds())) / 2 );

		sf::Vector2f x = sf::Vector2f(
			WorldObject::get_position().x + ((WorldObject::get_object_team()) ? 0.3 : -0.3),
			WorldObject::get_position().y + gravity);

		WorldObject::set_position(x);
	}
}

//--------------------------------------------------
bool AirBomb::collied(std::list <std::shared_ptr <Fighter>>& enemies, const sf::Vector2f& floorPosition) const {
	int fighternum = 0;
	for (auto fighter = enemies.begin(); fighter != enemies.end(); ++fighter)
		if (create(0).getGlobalBounds().intersects(fighter->get()->create(0).getGlobalBounds())) {
			if (!(*fighter)->getDamaged(m_damage))
				(*fighter)->setAnimationType(AnimationType::Die);
			*m_hit = true;
			return true;
		}
	if (create(0).getPosition().y + create(0).getGlobalBounds().height >= floorPosition.y) {
		*m_hit = true;
		return true;
	}
	return false;
}

//-------------------------------------------------
void AirBomb::draw(float delta) const {
	Window::instance().get_window()->draw(create(delta));
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite AirBomb::create(float f) const {
	auto result = sf::Sprite(*(m_animation->get_texture()));

	m_animation->update(f);

	result.setPosition(WorldObject::get_position());
	result.setScale(70.0f / result.getLocalBounds().width,
		50.0f / result.getLocalBounds().height);
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}