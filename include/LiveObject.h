#pragma once
#include "WorldObject.h"

class LiveObject : public WorldObject {
public:
	LiveObject(const sf::Vector2f&, const int&, const int&);

	int getHealth()const;
	void setHealth(const int&);
	bool getDamaged(const int&);

private:
	int m_health;
};
