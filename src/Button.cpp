#pragma once

#include "Button.h"

Button::Button(sf::Vector2f position) :
	m_position(position)
{}

void Button::draw() const {
	(Window::instance().get_window())->draw(create());
}

bool Button::handle_click(const sf::Vector2f location) const {
	return create().getGlobalBounds().contains(location);
}

