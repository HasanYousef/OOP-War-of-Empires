#pragma once
#include "AnimatedObject.h"
#include "TurettAnimation.h"
#include "Bullet.h"

class Turett : public AnimatedObject {
public:
	Turett(const sf::Vector2f&, bool);
	sf::Sprite create(float delta);
	std::shared_ptr<Bullet> shoot();

private:
	bool m_isShooting = false;
	TurettType m_level = TurettType::Turett1;
	float m_deg;
	TurettAnimation m_animation;
};
