#pragma once

#include "BuyWorldObject.h"

BuyWorldObject::BuyWorldObject(sf::Vector2f pos, int price)
	: m_position(pos), m_background(pos) {
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
	draw_object();
	m_button->draw();
}

bool BuyWorldObject::handle_click(const sf::Vector2f location) const {
	return m_button->handle_click(location);
}