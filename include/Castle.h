#pragma once
#include "LiveObject.h"

class Castle : public LiveObject {
public:
	Castle(const sf::Vector2f& p, const int& objectTeam);

	sf::Sprite create(float) const;
};