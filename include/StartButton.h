#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class StartButton : public Button {
public:
	StartButton();
	sf::Sprite create() const;
};