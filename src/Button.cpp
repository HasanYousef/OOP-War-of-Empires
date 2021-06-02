#pragma once

#include "Button.h"

Button::Button(sf::Vector2f position) :
	m_position(position)
{}

sf::RectangleShape Button::create() const {
	auto result = sf::RectangleShape({ BUTTON_WIDTH, BUTTON_HEIGHT });
	result.setPosition(m_position);
	result.setFillColor(sf::Color::Blue);
	return result;
}

void Button::handle_click(const sf::Vector2f location) const {
	if (create().getGlobalBounds().contains(location)) {
		run_action();
	}
}

