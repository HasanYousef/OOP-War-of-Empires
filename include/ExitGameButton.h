#pragma once

#include <SFML/Graphics.hpp>
#include "Button.h"

class ExitGameButton : public Button {
public:
	ExitGameButton();
	sf::Sprite create() const;
};