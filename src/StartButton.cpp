#pragma once

#include "StartButton.h"

StartButton::StartButton() : Button({100, 100})
{}

sf::Sprite StartButton::create() const {
	sf::Sprite button = sf::Sprite(*(Textures::instance().get_ui_texture(UITexture::StartButton)));
	button.setPosition({ m_position.x, m_position.y });
	return button;
}

