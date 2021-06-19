#pragma once
#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pos, float deg, int damage, bool team)
	: WorldObject(pos, team), m_deg(deg), m_damage(damage) {}

void Bullet::move() {
	m_position.x = m_position.x + 4 * cos(m_deg * PI / 180);
	m_position.y = m_position.y + 4 * sin(m_deg * PI / 180);
}

bool Bullet::collied(std::shared_ptr <std::list <std::shared_ptr <Fighter>>> enemies) const {
	int fighternum = 0;
	for (auto fighter = enemies->begin(); fighter != enemies->end(); ++fighter)
		if (create(0).getGlobalBounds().intersects(fighter->get()->create(0).getGlobalBounds()))
			return true;
	return false;
}

sf::Sprite Bullet::create(float) const {
	auto sprite = sf::Sprite(*Textures::instance().get_bullet());
	sprite.setPosition(m_position);
	sprite.setScale(0.5, 0.5);
	sf::FloatRect spriteRect = sprite.getLocalBounds();
	sprite.setOrigin(spriteRect.left + spriteRect.width / 2.0f,
		spriteRect.top + spriteRect.height / 2.0f);
	sprite.rotate(m_deg);
	return sprite;
}