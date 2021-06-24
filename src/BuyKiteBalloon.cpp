#pragma once

#include "BuyKiteBalloon.h"

BuyKiteBalloon::BuyKiteBalloon(sf::Vector2f pos)
	: BuyWorldObject(pos, 0) {
	m_button = std::make_unique<BuyKiteBalloonButton>(BuyKiteBalloonButton(pos, 0));
}

void BuyKiteBalloon::setCanBuy(bool can) {
	m_button->setCanBuy(can);
}

bool BuyKiteBalloon::handleClick(const sf::Vector2f location) {
	return m_button->handleClick(location);
}

void BuyKiteBalloon::drawObject() const {
	sf::Sprite balloon(*Textures::instance().getKiteBalloonTexture(1, 0));
	balloon.scale(0.15, 0.15);
	sf::FloatRect Rect = balloon.getLocalBounds();
	balloon.setOrigin(Rect.left + Rect.width / 2.0f,
		Rect.top + Rect.height / 2.0f);
	balloon.setPosition(m_position.x + 55, m_position.y + 50);
	Window::instance().getWindow()->draw(balloon);
}

void BuyKiteBalloon::draw() const {
	m_background.draw();
	drawObject();
	m_button->draw();
}