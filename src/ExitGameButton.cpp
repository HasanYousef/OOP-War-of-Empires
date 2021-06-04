#pragma once

#include "ExitGameButton.h"

// 270, 940
ExitGameButton::ExitGameButton() : Button({270, 940})
{}

sf::Sprite ExitGameButton::create() const {
	return Button::create(UITexture::ExitGameButton);
}

