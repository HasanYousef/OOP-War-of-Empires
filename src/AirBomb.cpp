#pragma once
#include "AirBomb.h"

AirBomb::AirBomb(const sf::Vector2f& p, const bool& objectTeam, const int& damage, const int& level)
	: AirUnites(p, objectTeam, damage),
	m_animation(std::make_shared<AirBombAnimation>()),
	m_movementClock(std::make_shared<sf::Clock>()),
	m_gravityClock(std::make_shared<sf::Clock>()),
	m_explosionDone(std::make_shared<bool>(false)), m_level(level > 2?2:level){}

//-------------------------------------------------
void AirBomb::move() {
	if (m_movementClock->getElapsedTime().asMilliseconds() > m_xMovementSpeed && *m_hit == false) {
		m_movementClock->restart();
		// moving enemy
		double gravity = std::sqrt( ( (m_gravityClock->getElapsedTime().asSeconds()) * 
			(m_gravityClock->getElapsedTime().asSeconds())) / 2 );

		sf::Vector2f x = sf::Vector2f(
			WorldObject::getPosition().x + ((WorldObject::getObjectTeam()) ? 0.3 : -0.3),
			WorldObject::getPosition().y + gravity);

		WorldObject::setPosition(x);
	}
}

//--------------------------------------------------
bool AirBomb::collied(std::list <std::shared_ptr <Fighter>>& enemies, const sf::Vector2f& floorPosition) const {
	if (*m_hit == false) {
		int fighternum = 0;
		for (auto fighter = enemies.begin(); fighter != enemies.end(); ++fighter)
			if (create(0).getGlobalBounds().intersects(fighter->get()->create(0).getGlobalBounds())) {
				if (!(*fighter)->getDamaged(m_damage))
					(*fighter)->setAnimationType(AnimationType::Die);
				*m_hit = true;
				Sounds::instance().getSound(SoundType::ExplosionSoundEffect)->play();
				return true;
			}
		if (create(0).getPosition().y + create(0).getGlobalBounds().height >= floorPosition.y) {
			*m_hit = true;
			Sounds::instance().getSound(SoundType::ExplosionSoundEffect)->play();
			return true;
		}

		return false;
	}
	else
		return false; // already collidedy
}

bool AirBomb::getHit() {
	return *m_explosionDone;
}

//-------------------------------------------------
void AirBomb::draw(float delta) const {
	Window::instance().getWindow()->draw(create(delta));
}

//-------------------------------------------------
//we creat the texture that we want to print it 

sf::Sprite AirBomb::create(float f) const {
	if (*m_hit && m_animation->getCurrFrame() == 0) {
		m_animation->setAnim();
	}

	m_animation->setAnimModule(m_level);

	auto result = sf::Sprite(*(m_animation->getTexture()));

	if(m_animation->update(f))
		*m_explosionDone = true;

	result.setPosition(WorldObject::getPosition());
	result.setScale(30.0f / result.getLocalBounds().width,
		20.0f / result.getLocalBounds().height);
	if (*m_hit) {
		result.setScale(150.0f / result.getLocalBounds().width,
			150.0f / result.getLocalBounds().height);
		result.setPosition(result.getPosition() + sf::Vector2f(result.getGlobalBounds().width * (0.4) *(m_objectTeam ? -1:1),
			- result.getGlobalBounds().height*0.4));
	}
	if (WorldObject::getObjectTeam() == RIGHT_TEAM)
		result.scale(-1.f, 1.f);
	return result;
}