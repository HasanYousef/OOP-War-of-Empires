#pragma once

#include <Empire.h>

Empire::Empire(bool team) : m_team(team),
m_castle(std::make_shared<Castle>(sf::Vector2f(m_team ? 0 : 1920, 768.75), m_team)) {}

void Empire::addFighter(std::shared_ptr <Fighter> fighter) {
	m_fighters.push_front(fighter);
}

void Empire::addKiteBalloon() {
	m_kiteBalloon = std::make_shared<KiteBalloon>(sf::Vector2f(m_team ? 0 : 1920, 20), m_team);
}

void Empire::moveKiteBalloon() {
	if (m_kiteBalloon != NULL) {
		m_kiteBalloon->move();
		if (((m_team == LEFT_TEAM) ? m_kiteBalloon->getPosition().x > 1920 : m_kiteBalloon->getPosition().x < 0))
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
	for (int i = 0; i < NUM_OF_TURETTS_STANDS; i++)
		if (m_turetts[i])
			m_turetts[i]->aim(enemyFighter);
}

void Empire::draw(float delta) const {
	m_castle->draw(0);
	if(m_kiteBalloon)
		m_kiteBalloon->draw(delta);
	if (m_kiteBalloon != NULL)
		m_kiteBalloon->draw(delta);

	for (auto& fighter : m_fighters)
		fighter->draw(delta);

	for (int i = 0; i < NUM_OF_TURETTS_STANDS; i++)
		if(m_turetts[i])
			m_turetts[i]->draw(delta);

	for (auto airUnit : m_airUnites)
		airUnit->draw(delta);
}

void Empire::attackFighters(std::shared_ptr <Castle> castle, std::shared_ptr <Fighter> enemyFighter) {
	for (auto fighter = m_fighters.begin(); fighter != m_fighters.end(); ++fighter) {
		fighter->get()->attack(enemyFighter, castle);
		if (enemyFighter.get() != NULL && *enemyFighter->fullyDead()) {
			return;
		}
	}
}

void Empire::collectEnemyMoney(const std::list<std::shared_ptr<Fighter>>& enemies) {
	for(std::shared_ptr<Fighter> enemyFighter : enemies)
		if (enemyFighter.get() != NULL && *enemyFighter->fullyDead())
			m_money += int(enemyFighter->getGoldWorth()) * 1.25;
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

int Empire::getFightersNum() const {
	return m_fighters.size();
}

void Empire::getLayedBomb() {
	if (m_kiteBalloon != NULL) {
		auto bomb = m_kiteBalloon->dropBomb();
		if (bomb != NULL)
			m_airUnites.push_back(bomb);
	}
}

void Empire::getSentBullet() {
	for (int i = 0; i < NUM_OF_TURETTS_STANDS; i++) {
		if (m_turetts[i]) {
			auto bullet = m_turetts[i]->shoot();
			if (bullet != NULL)
				m_airUnites.push_back(bullet);
		}
	}
}

void Empire::giveMoney(int money){
	m_money += money;
}

int Empire::buyTurett(int stand) {
	if (stand != 0 && stand != 1)
		return -1;

	auto pos = sf::Vector2f((m_team ? 105 : 1920 - 105) - stand * 15, 820 + stand * 70);
	if (!m_turetts[stand]) {
		if (m_money >= TURETT1_PRICE) {
			m_turetts[stand] = std::make_unique<Turett1>(pos, m_team);
			m_money -= TURETT1_PRICE;
			return int(TurettType::Turett1);
		}
	}
	else {
		TurettType currType = m_turetts[stand]->getType();
		if(currType == TurettType::Turett1 && m_money >= TURETT2_PRICE) {
			m_turetts[stand] = std::make_unique<Turett2>(pos, m_team);
			m_money -= TURETT2_PRICE;
			return int(TurettType::Turett2);
		}
		else if (currType == TurettType::Turett2 && m_money >= TURETT3_PRICE) {
			m_turetts[stand] = std::make_unique<Turett3>(pos, m_team);
			m_money -= TURETT3_PRICE;
			return int(TurettType::Turett3);
		}
	}
	return -1;
}

std::shared_ptr <Castle> Empire::getCastle() {
	return m_castle;
}

std::shared_ptr <Fighter> Empire::getFirstFighter() {
	for (auto fighter = m_fighters.rbegin(); fighter != m_fighters.rend(); ++fighter)
		if ((*fighter)->getHealth() > 0)
			return (*fighter);
	return std::shared_ptr<Fighter>(nullptr);
}

std::list<std::shared_ptr<Fighter>>& Empire::getFighters() {
	return m_fighters;
}

void Empire::moveAirUnites() {
	for (auto airUnit : m_airUnites)
		airUnit->move();
}
void Empire::colliedAirUnites(std::list <std::shared_ptr <Fighter>>& enemies, const sf::Vector2f& floorPosition) {
	for (auto airUnit : m_airUnites)
		airUnit->collied(enemies, floorPosition);
	m_airUnites.remove_if([](std::shared_ptr<AirUnites> airUnit)
		{return (*airUnit).getHit(); });
}