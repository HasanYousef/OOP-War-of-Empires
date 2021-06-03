#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Textures.h"
#include "macros.h"

class Button {
public:
	Button(sf::Vector2f);
	void draw() const;
	bool handle_click(const sf::Vector2f location) const;
	virtual sf::Sprite create() const = 0;
protected:
	sf::Vector2f m_position;
};