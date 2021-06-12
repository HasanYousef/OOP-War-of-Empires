#pragma once

#include "BuyWorldObjectBackground.h"

BuyWorldObjectBackground::BuyWorldObjectBackground(sf::Vector2f pos) : UIObject(pos)
{}

sf::Sprite BuyWorldObjectBackground::create() const {
	return UIObject::create(UITexture::BuyWorldObjectBackground);
}

