#pragma once

#include "BuyWorldObject.h"

BuyWorldObject::BuyWorldObject(sf::Vector2f pos, int price)
	: m_position(pos), m_background(pos) {
	m_button = std::make_unique<BuyButton>(BuyButton(pos, price));
}

void BuyWorldObject::setCanBuy(bool can) {
	m_button->setCanBuy(can);
}

int BuyWorldObject::getPrice() {
	return m_button->getPrice();
}

void BuyWorldObject::draw() const {
	m_background.draw();
	drawObject();
	m_button->draw();
}

bool BuyWorldObject::handleClick(const sf::Vector2f location) const {
	return m_button->handleClick(location);
}