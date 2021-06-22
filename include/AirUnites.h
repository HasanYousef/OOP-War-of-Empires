#pragma once
#include "AnimatedObject.h"
#include <list>
#include "Fighter.h"

class AirUnites : public AnimatedObject {
public:
		AirUnites() = default;
		AirUnites(const sf::Vector2f&, const bool&, const int&);

		virtual bool collied(std::list <std::shared_ptr <Fighter>>&, const sf::Vector2f&) const = 0;
		virtual void move() = 0;
		virtual bool getHit();

		virtual void draw(float) const = 0;
		virtual sf::Sprite create(float) const = 0;

protected:
	int m_damage;
	std::shared_ptr<bool> m_hit;
};