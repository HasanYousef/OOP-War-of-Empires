#pragma once
#include "AnimatedObject.h"
#include "AirBombAnimation.h"

class AirBomb : public AnimatedObject {
	AirBomb() = default;
	AirBomb(const sf::Vector2f&, const bool&);

	void move();

	virtual void draw(float) const;
	virtual sf::Sprite create(float) const;

private:
	std::shared_ptr<AirBombAnimation> m_animation;
	std::shared_ptr < sf::Clock> m_movementClock;
	std::shared_ptr<sf::Clock> m_gravityClock;
	float m_xMovementSpeed = FIGHTER_MOVEMENT_SPEED * 0.5,
		m_yMovementSpeed = 0;
};