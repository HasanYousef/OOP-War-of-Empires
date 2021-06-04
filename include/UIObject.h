#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Textures.h"
#include "macros.h"

class UIObject {
public:
	UIObject(sf::Vector2f);
	void draw() const;
	virtual sf::Sprite create(UITexture) const;
	virtual sf::Sprite create() const = 0;
protected:
	sf::Vector2f m_position;
};