#pragma once

#include <SFML/Graphics.hpp>
#include "UIObject.h"

class Button : public UIObject {
public:
	Button(sf::Vector2f);
	bool handle_click(const sf::Vector2f location) const;
};