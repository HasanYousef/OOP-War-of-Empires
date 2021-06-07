#pragma once

#include "MatchBackground.h"

MatchBackground::MatchBackground() : UIObject({0, 0})
{}

sf::Sprite MatchBackground::create() const {
	return UIObject::create(UITexture::MatchBackground);
}

