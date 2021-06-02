#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Textures.h"

class Button {
public:
	Button(sf::Vector2f);
	sf::RectangleShape create() const;
	void handle_click(const sf::Vector2f location) const;
	virtual void draw() const = 0;
	virtual void handle_click(const sf::Vector2f location) const = 0;
	virtual void run_action() const = 0;
protected:
	sf::Vector2f m_position;
};