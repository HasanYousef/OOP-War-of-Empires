#pragma once
#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pos, float deg, int damage, bool team)
	: AirUnites(pos, team, damage), m_deg(deg) {}

void Bullet::move() {
	m_position.x = m_position.x + 4 * cos(m_deg * PI / 180) * (m_objectTeam ? 1 : -1);
	m_position.y = m_position.y + 4 * sin(m_deg * PI / 180) * (m_objectTeam ? 1 : -1);
}

bool Bullet::collied(std::list <std::shared_ptr <Fighter>>& enemies, const sf::Vector2f& floorPosition) const {
	if (*m_hit == false) {
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
	else
		return false; // already collidedy
}

void Bullet::draw(float delta) const {
	Window::instance().getWindow()->draw(create(delta));
}

sf::Sprite Bullet::create(float) const {
	auto sprite = sf::Sprite(*Textures::instance().getBullet());
	sprite.setPosition(m_position);
	sprite.setScale(0.5, 0.5);
	sf::FloatRect spriteRect = sprite.getLocalBounds();
	sprite.setOrigin(spriteRect.left + spriteRect.width / 2.0f,
		spriteRect.top + spriteRect.height / 2.0f);
	sprite.rotate(m_deg);
	if (WorldObject::getObjectTeam() == RIGHT_TEAM)
		sprite.scale(-1.f, 1.f);
	return sprite;
}