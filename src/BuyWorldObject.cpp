#pragma once

#include "BuyWorldObject.h"

BuyWorldObject::BuyWorldObject(FighterType type, sf::Vector2f pos, int price)
	: m_position(pos), m_fighterType(type), m_background(pos) {
	m_button = std::make_unique<BuyButton>(BuyButton(pos, price));
}

void BuyWorldObject::set_can_buy(bool can) {
	m_button->set_can_buy(can);
}

int BuyWorldObject::get_price() {
	return m_button->get_price();
}

void BuyWorldObject::draw() const {
	m_background.draw();
	draw_fighter();
	m_button->draw();
}

void BuyWorldObject::draw_fighter() const {
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

bool BuyWorldObject::handle_click(const sf::Vector2f location) const {
	return m_button->handle_click(location);
}