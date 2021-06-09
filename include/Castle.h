#pragma once
#include "LiveObject.h"

class Castle : public LiveObject {
public:
	Castle() = default ;
	Castle(const sf::Vector2f&, const int&, const int&);

	//---build-body-----------
	virtual void draw(float) const;
	virtual sf::Sprite create(float) const;
};