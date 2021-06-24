#pragma once

#include "ExitGameButton.h"

ExitGameButton::ExitGameButton() : Button({270, 940})
{}

sf::Sprite ExitGameButton::create() const {
	return Button::create(UITexture::ExitGameButton);
}

