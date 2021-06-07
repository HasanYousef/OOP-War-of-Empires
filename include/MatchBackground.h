#pragma once

#include <SFML/Graphics.hpp>
#include "UIObject.h"
#include "Window.h"

class MatchBackground : public UIObject {
public:
	MatchBackground();
	sf::Sprite create() const;
};