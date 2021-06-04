#pragma once
#include "WorldObject.h"

class LiveObject : public WorldObject {
public:
	LiveObject();
	LiveObject(const WorldObjectType&, const sf::Vector2f&, 
				   const int&, const int&);

	void draw(sf::RenderWindow&) const;
	int getHealth()const;
	void setHealth(const int&);
	bool getDamaged(const int&);

	//---build-body-----------
	virtual sf::Sprite create() const;
private:
	int m_health;
};