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
	virtual void draw(float) const = 0;
	virtual sf::Sprite create(float) const = 0;
private:
	AnimationType m_animationType;
};