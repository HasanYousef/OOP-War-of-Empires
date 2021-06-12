#pragma once

#include "CastleHealthbarFilled.h"

CastleHealthbarFilled::CastleHealthbarFilled(bool team)
	: UIObject(team ? sf::Vector2f(30, 377) : sf::Vector2f(1872, 379))
{}

sf::Sprite CastleHealthbarFilled::create() const {
	return UIObject::create(UITexture::CastleHealthbar);
}

void CastleHealthbarFilled::update(int hp) {
	m_currHealth = hp;
}

void CastleHealthbarFilled::draw() const {
	UIObject::draw();
}