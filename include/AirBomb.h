#pragma once
#include "AirUnites.h"
#include "AirBombAnimation.h"
#include <math.h>

class AirBomb : public AirUnites {
public:
	AirBomb() = default;
	AirBomb(const sf::Vector2f&, const bool&, const int&);

	virtual void move();
	virtual void draw(float) const;
	virtual sf::Sprite create(float) const;

private:
	std::shared_ptr<AirBombAnimation> m_animation;
	std::shared_ptr < sf::Clock> m_movementClock;
	std::shared_ptr<sf::Clock> m_gravityClock;
	float m_xMovementSpeed = FIGHTER_MOVEMENT_SPEED * 0.5,
		m_yMovementSpeed = 0;
};