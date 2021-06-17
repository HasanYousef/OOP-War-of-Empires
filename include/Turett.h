#pragma once
#include "AnimatedObject.h"

class Turett : public AnimatedObject {
public:
	Turett(const sf::Vector2f&, const bool&);

	virtual sf::Sprite create(float) const;

private:
	bool m_isShooting = false;
};