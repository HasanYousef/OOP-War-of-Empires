#pragma once

#include "BuyFighter.h"

BuyFighter::BuyFighter(FighterType type, sf::Vector2f pos, int price)
	: BuyWorldObject(pos, price), m_fighterType(type) {
}

void BuyFighter::draw_object() const {
	sf::Sprite fighter(*Textures::instance().get_animation_texture(m_fighterType, AnimationType::Idle, 0));
	fighter.scale(0.8, 0.8);
	if (m_fighterType == FighterType::Tank3) {
		fighter.setScale(150.0f / fighter.getLocalBounds().width,
			150.0f / fighter.getLocalBounds().height);
	}
	sf::FloatRect Rect = fighter.getLocalBounds();
	fighter.setOrigin(Rect.left + Rect.width / 2.0f,
		Rect.top + Rect.height / 2.0f);
	fighter.setPosition(m_position.x + 55, m_position.y + 50);
	Window::instance().get_window()->draw(fighter);
}