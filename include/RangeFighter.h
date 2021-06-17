#pragma once
#include "Fighter.h"
#include "GunFire.h"
#include <iostream>
#include <math.h>

class RangeFighter : public Fighter {
public:
	RangeFighter() = default;
	RangeFighter(const sf::Vector2f&,
		const int&, const int&, const int&, const int&);

	virtual std::shared_ptr<bool> fullyDead() const;
	std::shared_ptr<GunFire> getGunFire() const;
	std::shared_ptr<sf::Clock> getMovementClock() const;

	virtual void attack(const std::shared_ptr<Fighter>& firstEnemy,
		const std::shared_ptr<Castle>& Castle);
	virtual void move(const std::shared_ptr<Fighter>& nextAlly,
		const std::shared_ptr<Fighter>& firstEnemy,
		const std::shared_ptr<Castle>& Castle);

	virtual void draw(float) const;
	virtual sf::Sprite create(float) const;
private:
	sf::Clock m_attackClock;
	std::shared_ptr <sf::Clock> m_movementClock;
	std::shared_ptr<GunFire> m_gunFire;
};

float getDistance(const sf::Sprite&, const sf::Sprite&);