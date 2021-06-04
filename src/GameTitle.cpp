#pragma once

#include "GameTitle.h"

GameTitle::GameTitle() : UIObject({100, 100})
{}

sf::Sprite GameTitle::create() const {
	sf::Sprite sprite = UIObject::create(UITexture::GameTitle);
	sprite.scale({ 1.1, 1.1 });
	return sprite;
}

