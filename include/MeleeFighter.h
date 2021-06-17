#pragma once
#include "Fighter.h"
#include <iostream>

class MeleeFighter : public Fighter {
public:
	MeleeFighter() = default;
	MeleeFighter(const sf::Vector2f&,
		const int&, const int&, const int&, const int&);

	virtual std::shared_ptr<bool> fullyDead() const;

	virtual void attack(const std::shared_ptr<Fighter>& firstEnemy, 
		const std::shared_ptr<Castle>& Castle);

	virtual void draw(float) const;
	virtual sf::Sprite create(float) const;
private:
	sf::Clock m_attackClock;
};