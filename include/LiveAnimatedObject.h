#pragma once
#include "AnimatedObject.h"
#include "LiveObject.h"

class LiveAnimatedObject : public AnimatedObject, public LiveObject {
public:
	LiveAnimatedObject();
	LiveAnimatedObject(const WorldObjectType&, const sf::Vector2f&,
		const int&, const int&);

	virtual sf::Sprite create() const;
};