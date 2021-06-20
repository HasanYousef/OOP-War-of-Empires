#pragma once
#include "AirUnites.h"

class Bullet : public AirUnites {
public:
	Bullet(sf::Vector2f, float, int, bool);
	virtual void move();
	virtual bool collied(std::list <std::shared_ptr <Fighter>>& enemies, const sf::Vector2f&) const;
	virtual void draw(float) const;
	virtual sf::Sprite create(float) const;

private:
	float m_deg;
};