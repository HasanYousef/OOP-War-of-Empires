#pragma once
#include <list>
#include "WorldObject.h"
#include "Fighter.h"

class Bullet : public WorldObject {
public:
	Bullet(sf::Vector2f, float, int, bool);
	void move();
	bool collied(std::shared_ptr <std::list <std::shared_ptr <Fighter>>>) const;
	sf::Sprite create(float) const;

private:
	float m_deg;
	int m_damage;
};