#pragma once

#include "StartButton.h"

// 50, 940
StartButton::StartButton() : Button({50, 940})
{}

sf::Sprite StartButton::create() const {
	return Button::create(UITexture::StartButton);
}

