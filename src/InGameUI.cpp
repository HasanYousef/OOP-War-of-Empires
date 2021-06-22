#pragma once

#include "InGameUI.h"

InGameUI::InGameUI()
	: m_leftCastleHealthbar(LEFT_TEAM, CASTLE_MAX_HEALTH), m_rightCastleHealthbar(RIGHT_TEAM, CASTLE_MAX_HEALTH)
{
	int i = 0;
	for (; i < NUM_OF_FIGHTER_TYPES; i++) {
		sf::Vector2f pos(16 * (i + 1) + 110 * i, 16);
		m_shop.push_back(std::make_unique<BuyFighter>(FighterType(i), pos, 100 * (i + 1)));
	}
	for (; i < 2 + NUM_OF_FIGHTER_TYPES; i++) {
		sf::Vector2f pos(16 * (i + 1) + 110 * i, 16);
		m_shop.push_back(std::make_unique<BuyTurett>(pos));
	}
}

void InGameUI::update(int money, int playerHealth, int enemyHealth) {
	for (int i = 0; i < m_shop.size(); i++) {
		if (m_shop[i])
			m_shop[i]->set_can_buy(money >= m_shop[i]->get_price());
	}
	m_leftCastleHealthbar.update(playerHealth);
	m_rightCastleHealthbar.update(enemyHealth);
	m_money = money;
}

void InGameUI::draw() const {
	for (int i = 0; i < m_shop.size(); i++)
		if(m_shop[i])
			m_shop[i]->draw();
	m_leftCastleHealthbar.draw();
	m_rightCastleHealthbar.draw();
	drawMoney(m_money);
}

void InGameUI::drawMoney(int money) const {
	sf::Text text;
	text.setString("$" + std::to_string(money));
	text.setFont(*Textures::instance().get_font());
	text.setCharacterSize(32);
	text.setPosition(14, 290);

	Window::instance().get_window()->draw(text);
}

FighterType InGameUI::handle_click_fighters(const sf::Vector2f location) const {
	for (int i = 0; i < NUM_OF_FIGHTER_TYPES; i++)
		if (m_shop[i] && m_shop[i]->handle_click(location))
			return FighterType(i);
	return FighterType::Nothing;
}

void InGameUI::setTurettType(int stand, int type) {
	if (type == NUM_OF_TURETT_TYPES)
		m_shop[stand + NUM_OF_FIGHTER_TYPES].release();
	else
		m_shop[NUM_OF_FIGHTER_TYPES + stand]->setType(type);
}

int InGameUI::handle_click_turetts(const sf::Vector2f location) const {
	for (int i = NUM_OF_FIGHTER_TYPES; i < m_shop.size(); i++)
		if (m_shop[i] && m_shop[i]->handle_click(location))
			return i - NUM_OF_FIGHTER_TYPES;
	return -1;
}
