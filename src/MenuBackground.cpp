#pragma once

#include "MenuBackground.h"

MenuBackground::MenuBackground() : UIObject({0, 0})
{}

sf::Sprite MenuBackground::create() const {
	return UIObject::create(UITexture::MenuBackground);
}

