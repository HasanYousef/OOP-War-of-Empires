#pragma once

#include "InGameUI.h"

InGameUI::InGameUI()
	: m_leftCastleHealthbar(LEFT_TEAM, CASTLE_MAX_HEALTH), m_rightCastleHealthbar(RIGHT_TEAM, CASTLE_MAX_HEALTH)
{
	std::vector<sf::Vector2f> positions;
	int i = 0;
	for (; i < NUM_OF_FIGHTER_TYPES; i++) {
		positions.push_back(sf::Vector2f(16 * (i + 1) + 110 * i, 16));
	}
	m_shop.push_back(std::make_unique<BuyFighter>(FighterType(0), positions[0], MELEE_1_WORTH));
	m_shop.push_back(std::make_unique<BuyFighter>(FighterType(1), positions[1], MELEE_2_WORTH));
	m_shop.push_back(std::make_unique<BuyFighter>(FighterType(2), positions[2], RANGE_1_WORTH));
	m_shop.push_back(std::make_unique<BuyFighter>(FighterType(3), positions[3], RANGE_2_WORTH));
	m_shop.push_back(std::make_unique<BuyFighter>(FighterType(4), positions[4], RANGE_3_WORTH));
	m_shop.push_back(std::make_unique<BuyFighter>(FighterType(5), positions[5], RANGE_4_WORTH));
	for (; i < 2 + NUM_OF_FIGHTER_TYPES; i++)
		m_shop.push_back(std::make_unique<BuyTurett>(sf::Vector2f(16 * (i + 1) + 110 * i, 16)));
	m_kiteBalloon =  std::make_unique<BuyKiteBalloon>(sf::Vector2f(16 * (i + 1) + 110 * i, 16));
}

void InGameUI::update(int money, int playerHealth, int enemyHealth) {
	for (int i = 0; i < m_shop.size(); i++) {
		if (m_shop[i])
			m_shop[i]->setCanBuy(money >= m_shop[i]->getPrice());
	}
	m_kiteBalloon->setCanBuy(true);
	m_leftCastleHealthbar.update(playerHealth);
	m_rightCastleHealthbar.update(enemyHealth);
	m_money = money;
}

void InGameUI::draw() const {
	for (int i = 0; i < m_shop.size(); i++)
		if(m_shop[i])
			m_shop[i]->draw();
	m_kiteBalloon->draw();
	m_leftCastleHealthbar.draw();
	m_rightCastleHealthbar.draw();
	drawMoney(m_money);
}

void InGameUI::drawMoney(int money) const {
	sf::Text text;
	text.setString("$" + std::to_string(money));
	text.setFont(*Textures::instance().getFont());
	text.setCharacterSize(32);
	text.setPosition(14, 290);

	Window::instance().getWindow()->draw(text);
}

FighterType InGameUI::handleClickFighters(const sf::Vector2f location) const {
	for (int i = 0; i < NUM_OF_FIGHTER_TYPES; i++)
		if (m_shop[i] && m_shop[i]->handleClick(location))
			return FighterType(i);
	return FighterType::Nothing;
}

int InGameUI::handleClickTuretts(const sf::Vector2f location) const {
	for (int i = NUM_OF_FIGHTER_TYPES; i < m_shop.size(); i++)
		if (m_shop[i] && m_shop[i]->handleClick(location))
			return i - NUM_OF_FIGHTER_TYPES;
	return -1;
}

bool InGameUI::handleClickBalloon(const sf::Vector2f location) const {
	return m_kiteBalloon->handleClick(location);
}

void InGameUI::setTurettType(int stand, int type) {
	if (type == NUM_OF_TURETT_TYPES)
		m_shop[stand + NUM_OF_FIGHTER_TYPES].release();
	else
		m_shop[NUM_OF_FIGHTER_TYPES + stand]->setType(type);
}