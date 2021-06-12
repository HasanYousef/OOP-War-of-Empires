#pragma once

#include <SFML/Graphics.hpp>
#include "UIObject.h"

class CastleHealthbarBackground : UIObject {
public:
	CastleHealthbarBackground(bool);
	void draw() const;
private:
	sf::Sprite create() const;
};