#pragma once

#include "CastleHealthbarFilled.h"

CastleHealthbarFilled::CastleHealthbarFilled(bool team, int maxHealth)
	: UIObject(team ? sf::Vector2f(33, 382) : sf::Vector2f(1875, 382)),
	m_maxHealth(maxHealth), m_currHealth(maxHealth)
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