#pragma once

#include "BuyKiteBalloonButton.h"

BuyKiteBalloonButton::BuyKiteBalloonButton(sf::Vector2f pos, int price)
	: BuyButton(pos, price) {}

sf::Sprite BuyKiteBalloonButton::create() const {
	sf::Sprite butt = Button::create(m_canBuy ? UITexture::ActiveButton : UITexture::UnactiveButton);
	butt.scale(0.8, 0.8);
	return butt;
}

void BuyKiteBalloonButton::draw() const {
	Button::draw();
	m_canBuyMore ? drawPrice() : drawBought();
}

void BuyKiteBalloonButton::setCanBuy(bool canBuy) {
	m_canBuy = canBuy && m_clock.getElapsedTime().asSeconds() > BALLOON_TIME;
}

void BuyKiteBalloonButton::drawPrice() const {
	sf::Text priceText;
	int time = BALLOON_TIME - int(m_clock.getElapsedTime().asSeconds());
	if (!m_canBuy)
		priceText.setString(std::to_string(time) + "s");
	else
		priceText.setString("Release");
	priceText.setFont(*Textures::instance().getFont());
	priceText.setCharacterSize(20);
	priceText.setColor(m_canBuy ? sf::Color::White : sf::Color(185, 185, 185));
	sf::FloatRect textRect = priceText.getLocalBounds();
	priceText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	priceText.setPosition(m_position.x + 46, m_position.y + 14);
	Window::instance().getWindow()->draw(priceText);
}

void BuyKiteBalloonButton::drawBought() const {
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

bool BuyKiteBalloonButton::handleClick(const sf::Vector2f location) {
	if (m_canBuy && Button::handleClick(location)) {
		m_clock.restart();
		m_canBuy = false;
		return true;
	}
	return false;
}