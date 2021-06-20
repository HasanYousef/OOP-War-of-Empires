#pragma once
#include "AnimatedObject.h"
#include <list>
#include "Fighter.h"

class AirUnites : public AnimatedObject {
public:
		AirUnites() = default;
		AirUnites(const sf::Vector2f&, const bool&, const int&);

		bool collied(std::list <std::shared_ptr <Fighter>>&, const sf::Vector2f&);
		virtual void move() = 0;
		bool getHit();

		virtual void draw(float) const = 0;
		virtual sf::Sprite create(float) const = 0;

protected:
	int m_damage;
	bool m_hit = false;
};