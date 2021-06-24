#pragma once
#include "Turett.h"

Turett::Turett(const sf::Vector2f& pos, bool team)
	: AnimatedObject(pos, team), m_shootClock(std::make_shared<sf::Clock>()){
}

sf::Sprite Turett::create(float delta) const {
	sf::Sprite sprite;
	if (m_animation->isShooting()) {
		sprite = sf::Sprite(*(m_animation->getTexture()));
		if (m_animation->update(delta)) m_animation->setIsShooting(false);
	}
	else
		sprite = sf::Sprite(*Textures::instance().getTurettTexture(getType(), 0));

	sprite.setPosition(WorldObject::getPosition());
	sprite.rotate(m_deg);
	sf::FloatRect spriteRect = sprite.getLocalBounds();
	sprite.setOrigin(spriteRect.left + spriteRect.width / 2.0f,
		spriteRect.top + spriteRect.height / 2.0f);
	if (WorldObject::getObjectTeam() == RIGHT_TEAM) {
		sprite.scale(-1.f, 1.f);
	}
	sprite.scale(0.2, 0.2);
	return sprite;
}

void Turett::aim(const std::shared_ptr<Fighter>& enemy) {
	if (enemy && getDistance(create(0), enemy->create(0)) <= TOWER_RANGE) {
		m_isShooting = true;
		auto enemyPos = enemy->create(0).getPosition();
		enemyPos.y += enemy->create(0).getGlobalBounds().height;
		float opposite = enemyPos.x - m_position.x;
		float adjacent = enemyPos.y - m_position.y;
		bool team = WorldObject::getObjectTeam();
		if (!team)
			opposite *= -1;
		m_deg = 90 - atan(opposite / adjacent) * 180 / PI;
		if (!team)
			m_deg *= -1;
	}
	else
		m_isShooting = false;
}

std::shared_ptr<Bullet> Turett::shoot() {
	if (m_shootClock->getElapsedTime().asSeconds() > 0.5 && m_isShooting) {
		m_shootClock->restart();
		auto bullet = std::make_shared<Bullet>(m_position, m_deg, getDamage(), WorldObject::getObjectTeam());
		return bullet;
	}
	return NULL;
}