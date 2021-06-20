#pragma once
#include "AnimatedObject.h"
#include "TurettAnimation.h"
#include "Bullet.h"

class Turett : public AnimatedObject {
public:
	Turett(const sf::Vector2f&, bool);
	sf::Sprite create(float delta) const;
	void aim(const std::shared_ptr<Fighter>& enemy);
	std::shared_ptr<Bullet> shoot();

private:
	bool m_isShooting = false;
	TurettType m_level = TurettType::Turett3;
	float m_deg = 0;
	std::unique_ptr<TurettAnimation> m_animation;
	std::shared_ptr<sf::Clock> m_shootClock;
};
