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
	virtual TurettType getType() const = 0;
	virtual int getDamage() const = 0;

protected:
	std::unique_ptr<TurettAnimation> m_animation;

private:
	bool m_isShooting = false;
	float m_deg = 0;
	std::shared_ptr<sf::Clock> m_shootClock;
};
