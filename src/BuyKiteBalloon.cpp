#pragma once

#include "BuyKiteBalloon.h"

BuyKiteBalloon::BuyKiteBalloon(sf::Vector2f pos)
	: BuyWorldObject(pos, 0) {
	m_button = std::make_unique<BuyKiteBalloonButton>(BuyKiteBalloonButton(pos, 0));
}

void BuyKiteBalloon::set_can_buy(bool can) {
	m_button->set_can_buy(can);
}

void BuyKiteBalloon::draw_object() const {
	sf::Sprite balloon(*Textures::instance().get_kite_balloon_texture(1, 0));
	balloon.scale(0.15, 0.15);
	/*if (m_fighterType == FighterType::Tank3) {
		fighter.setScale(150.0f / fighter.getLocalBounds().width,
			150.0f / fighter.getLocalBounds().height);
	}*/
	sf::FloatRect Rect = balloon.getLocalBounds();
	balloon.setOrigin(Rect.left + Rect.width / 2.0f,
		Rect.top + Rect.height / 2.0f);
	balloon.setPosition(m_position.x + 55, m_position.y + 50);
	Window::instance().get_window()->draw(balloon);
}

void BuyKiteBalloon::draw() const {
	m_background.draw();
	draw_object();
	m_button->draw();
}