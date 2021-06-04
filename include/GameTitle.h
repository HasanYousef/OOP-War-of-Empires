#pragma once

#include <SFML/Graphics.hpp>
#include "UIObject.h"

class GameTitle : public UIObject {
public:
	GameTitle();
	sf::Sprite create() const;
};