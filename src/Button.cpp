#pragma once

#include "Button.h"

Button::Button(sf::Vector2f position) :
	UIObject(position)
{}

bool Button::handleClick(const sf::Vector2f location) {
	return create().getGlobalBounds().contains(location);
}

