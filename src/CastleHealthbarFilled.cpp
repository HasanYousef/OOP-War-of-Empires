#pragma once

#include "CastleHealthbarFilled.h"

CastleHealthbarFilled::CastleHealthbarFilled(bool team, float maxHealth)
	: UIObject(team ? sf::Vector2f(33, 611) : sf::Vector2f(1875, 611)),
	m_maxHealth(maxHealth), m_currHealth(maxHealth)
{}

sf::Sprite CastleHealthbarFilled::create() const {
	sf::Sprite bar = UIObject::create(UITexture::CastleHealthbar);
	sf::FloatRect barRect = bar.getLocalBounds();
	bar.setOrigin(0, barRect.top + barRect.height);
	bar.scale(1, float(m_currHealth) / float(m_maxHealth));
	return bar;
}

void CastleHealthbarFilled::drawText() const {
	sf::Text text;
	text.setString("%" + std::to_string(int(float(m_currHealth) / float(m_maxHealth) * 100)));
	text.setFont(*Textures::instance().getFont());
	text.setCharacterSize(24);
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text.setPosition(m_position.x + 4, m_position.y - 260);
	Window::instance().getWindow()->draw(text);
}

void CastleHealthbarFilled::update(int hp) {
	m_currHealth = hp;
}

void CastleHealthbarFilled::draw() const {
	UIObject::draw();
	drawText();
}