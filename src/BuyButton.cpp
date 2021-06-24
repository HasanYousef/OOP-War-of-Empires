#pragma once

#include "BuyButton.h"

BuyButton::BuyButton(sf::Vector2f pos, int price) 
	: Button({pos.x + 9, pos.y + 101}), m_price(price) {}

void BuyButton::setCanBuy(bool canBuy) {
	m_canBuy = canBuy;
}

void BuyButton::setPrice(int price) {
	m_price = price;
}

int BuyButton::getPrice() const {
	return m_price;
}

sf::Sprite BuyButton::create() const {
	sf::Sprite butt = Button::create(m_canBuy ? UITexture::ActiveButton : UITexture::UnactiveButton);
	butt.scale(0.8, 0.8);
	return butt;
}

void BuyButton::setCanBuyMore(bool can) {
	m_canBuy = can;
}

void BuyButton::draw() const {
	Button::draw();
	m_canBuyMore ? drawPrice() : drawBought();
}

void BuyButton::drawPrice() const {
	sf::Text priceText;
	priceText.setString("$" + std::to_string(m_price));
	priceText.setFont(*Textures::instance().getFont());
	priceText.setCharacterSize(20);
	priceText.setColor(m_canBuy ? sf::Color::White : sf::Color(185, 185, 185));
	sf::FloatRect textRect = priceText.getLocalBounds();
	priceText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	priceText.setPosition(m_position.x + 46, m_position.y + 14);
	Window::instance().getWindow()->draw(priceText);
}

void BuyButton::drawBought() const {
	sf::Text priceText;
	priceText.setString("Bought");
	priceText.setFont(*Textures::instance().getFont());
	priceText.setCharacterSize(20);
	priceText.setColor(sf::Color(185, 185, 185));
	sf::FloatRect textRect = priceText.getLocalBounds();
	priceText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	priceText.setPosition(m_position.x + 46, m_position.y + 14);
	Window::instance().getWindow()->draw(priceText);
}

bool BuyButton::handleClick(const sf::Vector2f location) {
	return m_canBuy && Button::handleClick(location);
}