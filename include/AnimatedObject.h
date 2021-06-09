#pragma once
#include "WorldObject.h"

class AnimatedObject : public WorldObject {
public:
	AnimatedObject() = default ;
	AnimatedObject(const sf::Vector2f&);
	AnimatedObject(const sf::Vector2f&, const bool&);

	void setAnimationType(const AnimationType&);
	AnimationType getAnimationType() const;

	//---build-body-----------
	virtual sf::Sprite create() const = 0;
	virtual void draw(sf::RenderWindow&) const = 0;
private:
	AnimationType m_animationType;
};