#pragma once

#include <Empire.h>

Empire::Empire(bool team) : m_team(team),
m_castle(std::make_shared<Castle>(sf::Vector2f(m_team ? 0 : 1920, 630), m_team)), m_turett(sf::Vector2f(m_team ? 200 : 1720, 600), m_team) {}

void Empire::addFighter(std::shared_ptr <Fighter> fighter) {
	m_fighters.push_front(fighter);
}

void Empire::addKiteBalloon() {
	m_kiteBalloon = std::make_shared<KiteBalloon>(sf::Vector2f(m_team ? 0 : 1920, 20), m_team);
}

void Empire::moveKiteBalloon() {
	if (m_kiteBalloon != NULL) {
		m_kiteBalloon->move();
		if (((m_team == LEFT_TEAM) ? m_kiteBalloon->get_position().x > 1920 : m_kiteBalloon->get_position().x < 0))
			m_kiteBalloon.reset();
	}
}

void Empire::moveFighters(std::shared_ptr <Castle> castle, std::shared_ptr <Fighter> enemyFighter) {
	int fighternum = 0;
	for (auto fighter = m_fighters.begin(); fighter != m_fighters.end(); ++fighter) {
		if (fighternum == m_fighters.size() - 1) {
			fighter->get()->move(NULL, enemyFighter, castle);
		}
		else if (fighternum < m_fighters.size()) {
			if (fighter->get()->getAnimationType() != AnimationType::Die) {
				auto frontFighter = *std::next(fighter);
				fighter->get()->move(frontFighter, enemyFighter, castle);
			}
		}
		fighternum++;
	}
	m_turett.aim(enemyFighter);
}

void Empire::draw(float delta) const {
	m_castle->draw(0);
	if(m_kiteBalloon)
		m_kiteBalloon->draw(delta);
	if (m_kiteBalloon != NULL)
		m_kiteBalloon->draw(delta);
	for (auto& fighter : m_fighters) {
		fighter->draw(delta);
	}
	m_turett.draw(delta);
}

void Empire::attackFighters(std::shared_ptr <Castle> castle, std::shared_ptr <Fighter> enemyFighter) {
	int fighternum = 0;
	for (auto fighter = m_fighters.begin(); fighter != m_fighters.end(); ++fighter) {
		fighter->get()->attack(enemyFighter, castle);
		if (enemyFighter.get() != NULL && *enemyFighter->fullyDead()) {
			m_money += int(enemyFighter->getGoldWorth());
			return;
		}
		fighternum++;
	}
}

void Empire::collectDead() {
	m_fighters.remove_if([](std::shared_ptr<Fighter> fighter)
		{ return (*fighter.get()->fullyDead()); });
}

void Empire::pay(int price) {
	m_money -= price;
}

bool Empire::ifGetOccupied() const {
	return (m_castle->getHealth() <= 0);
}

int Empire::getMoney() const {
	return m_money;
}

std::shared_ptr <Castle> Empire::getCastle() {
	return m_castle;
}

std::shared_ptr <Fighter> Empire::getFirstFighter() {
	std::shared_ptr<Fighter> temp(nullptr);
	return (m_fighters.size() > 0) ? m_fighters.back() : temp;
}
