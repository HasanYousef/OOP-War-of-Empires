#pragma once

#include "CastleHealthbarBackground.h"

CastleHealthbarBackground::CastleHealthbarBackground(bool team)
	: UIObject(team ? sf::Vector2f(30, 379) : sf::Vector2f(1872, 379))
{}

sf::Sprite CastleHealthbarBackground::create() const {
	return UIObject::create(UITexture::CastleHealthbarBackground);
}

void CastleHealthbarBackground::draw() const {
	UIObject::draw();
}