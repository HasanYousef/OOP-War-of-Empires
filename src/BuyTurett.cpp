#pragma once

#include "BuyTurett.h"

BuyTurett::BuyTurett(sf::Vector2f pos, int price)
	: BuyWorldObject(pos, price) {
}

void BuyTurett::draw_object() const {
	sf::Sprite turett(*Textures::instance().get_turett_texture(m_turettType, 0));
	turett.scale(0.4, 0.4);
	sf::FloatRect Rect = turett.getLocalBounds();
	turett.setOrigin(Rect.left + Rect.width / 2.0f,
		Rect.top + Rect.height / 2.0f);
	turett.setPosition(m_position.x + 55, m_position.y + 50);
	Window::instance().get_window()->draw(turett);
}