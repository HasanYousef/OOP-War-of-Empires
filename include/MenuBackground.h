#pragma once

#include <SFML/Graphics.hpp>
#include "UIObject.h"
#include "Window.h"

class MenuBackground : public UIObject {
public:
	MenuBackground();
	sf::Sprite create() const;
};