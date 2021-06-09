#pragma once
#include "WorldObject.h"

class LiveObject : public WorldObject {
public:
	LiveObject() = default ;
	LiveObject(const sf::Vector2f&, const int&, const int&);

	int getHealth()const;
	void setHealth(const int&);
	bool getDamaged(const int&);

	//---build-body-----------
	virtual void draw(float) const = 0;
	virtual sf::Sprite create(float) const = 0;
private:
	int m_health;
};
