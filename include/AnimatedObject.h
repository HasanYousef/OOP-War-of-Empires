#pragma once

#include "WorldObject.h"
#include "Animation.h"

class AnimatedObject : public WorldObject {
public:
	AnimatedObject(const sf::Vector2f&);
	AnimatedObject(const sf::Vector2f&, const bool&);

	//---build-body-----------
	virtual void draw(float delta) const { WorldObject::draw(delta); };
	virtual sf::Sprite create(float) const = 0;
};