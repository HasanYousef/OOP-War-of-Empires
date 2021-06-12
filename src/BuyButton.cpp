#pragma once

#include "BuyButton.h"

BuyButton::BuyButton(sf::Vector2f pos, int price) 
	: Button({pos.x + 9, pos.y + 101}), m_price(price) {}

void BuyButton::setCanBuy(bool canBuy) {
	m_canBuy = canBuy;
}

sf::Sprite BuyButton::create() const {
	sf::Sprite butt = Button::create(m_canBuy ? UITexture::ActiveButton : UITexture::UnactiveButton);
	butt.scale(0.8, 0.8);
	return butt;
}

void BuyButton::draw() const {
	Button::draw();
	draw_price();
}

void BuyButton::draw_price() const {
	sf::Text priceText;
	priceText.setString("$" + std::to_string(m_price));
	priceText.setFont(*Textures::instance().get_font());
	priceText.setCharacterSize(20);
	priceText.setColor(m_canBuy ? sf::Color::White : sf::Color(185, 185, 185));
	sf::FloatRect textRect = priceText.getLocalBounds();
	priceText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	priceText.setPosition(m_position.x + 46, m_position.y + 14);
	Window::instance().get_window()->draw(priceText);
}

bool BuyButton::handle_click(const sf::Vector2f location) const {
	return m_canBuy && Button::handle_click(location);
}