#pragma once

#include "BuyWorldObject.h"

BuyWorldObject::BuyWorldObject(FighterType type, sf::Vector2f pos, int price)
	: m_position(pos), m_fighterType(type), m_background(pos) {
	m_button = std::make_unique<BuyButton>(BuyButton(pos, price));
}

void BuyWorldObject::draw() const {
	m_background.draw();
	draw_fighter();
	m_button->draw();
}

void BuyWorldObject::draw_fighter() const {
	sf::Sprite fighter(*Textures::instance().get_animation_texture(m_fighterType, AnimationType::Idle, 0));
	fighter.scale(0.8, 0.8);
	sf::FloatRect Rect = fighter.getLocalBounds();
	fighter.setOrigin(Rect.left + Rect.width / 2.0f,
		Rect.top + Rect.height / 2.0f);
	fighter.setPosition(m_position.x + 55, m_position.y + 50);
	Window::instance().get_window()->draw(fighter);
}