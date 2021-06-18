#pragma once
#include "Turett.h"

Turett::Turett(const sf::Vector2f& pos, bool team)
	: AnimatedObject(pos, team), m_animation(TurettType::Turett1){
}

sf::Sprite Turett::create(float delta) {
	sf::Sprite sprite;
	if (m_isShooting) {
		sprite = sf::Sprite(*(m_animation.get_texture()));
		if (m_animation.update(delta)) m_isShooting = false;
	}
	else
		sprite = sf::Sprite(*Textures::instance().get_turett_texture(m_level, 0));

	sprite.setPosition(WorldObject::get_position());
	if (WorldObject::get_object_team() == RIGHT_TEAM)
		sprite.scale(-1.f, 1.f);
	return sprite;
}

std::shared_ptr<Bullet> Turett::shoot() {
	return std::make_shared<Bullet>(m_position, m_deg, 100, WorldObject::get_object_team());
}