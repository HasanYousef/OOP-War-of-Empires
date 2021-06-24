#pragma once

#include "AI.h"

void AI::bot(Empire& empire) {
	int spawn = 0;
	m_levelTime = m_clock.getElapsedTime();
	//change num of soilder every 120 sec
	if (m_levelTime.asSeconds() >= WAVE) {
		m_wave++;
		m_level++;
		if (m_level > 2) {
			m_level = 1;
		}
		empire.giveMoney(500 * m_wave);
		m_clock.restart();
		empire.addKiteBalloon();
	}
	// buy Turret if we can
	buyTurret(empire);
	// level up the fighter and ballon
	levelUp();

	sf::Vector2f spawnPos(empire.getCastle()->getObjectTeam() ? 20 : 1920, 1080 - 120);
	// buy tanks fighters
	if (empire.getFightersNum() < (2 + (m_level * 2))) {
		// buy a TANK VEHICLE
		if (m_tankFront && empire.getMoney() >= RANGE_4_WORTH) {
			empire.addFighter(std::make_shared<RangeFighter4>
				(spawnPos, empire.getCastle()->getObjectTeam()));
			empire.pay(RANGE_4_WORTH);
			m_tankFront = false;
		}

		if (empire.getMoney() >= MELEE_2_WORTH) {
			empire.addFighter(std::make_shared<MeleeFighter2>
				(spawnPos, empire.getCastle()->getObjectTeam()));
			empire.pay(MELEE_2_WORTH);
		}
		else if (empire.getMoney() >= MELEE_1_WORTH) {
			empire.addFighter(std::make_shared<MeleeFighter1>
				(spawnPos, empire.getCastle()->getObjectTeam()));
			empire.pay(MELEE_1_WORTH);
		}
		// by a shooters
		while (spawn < 2) {
			if (empire.getMoney() >= RANGE_3_WORTH) {
				empire.addFighter(std::make_shared<RangeFighter3>
					(spawnPos, empire.getCastle()->getObjectTeam()));
				empire.pay(RANGE_3_WORTH);
			}
			else if (empire.getMoney() >= RANGE_2_WORTH) {
				empire.addFighter(std::make_shared<RangeFighter2>
					(spawnPos, empire.getCastle()->getObjectTeam()));
				empire.pay(RANGE_2_WORTH);
			}
			else if (empire.getMoney() >= RANGE_1_WORTH) {
				empire.addFighter(std::make_shared<RangeFighter1>
					(spawnPos, empire.getCastle()->getObjectTeam()));
				empire.pay(RANGE_1_WORTH);
			}
			spawn++;
		}

		// buy a TANK VEHICLE
		if (!m_tankFront && empire.getMoney() >= RANGE_4_WORTH) {
			empire.addFighter(std::make_shared<RangeFighter4>
				(spawnPos, empire.getCastle()->getObjectTeam()));
			empire.pay(RANGE_4_WORTH);
			m_tankFront = true;
		}
	}
	if (empire.getFightersNum() == 0 && int(m_levelTime.asSeconds()) % (WAVE / 4) == 0) {
		empire.giveMoney(1000 * (m_wave + 1));
		empire.addKiteBalloon();
	}
}

void AI::buyTurret(Empire &empire) {
	switch (m_wave) {
	case 1:
		empire.giveMoney(TURETT1_PRICE);
		empire.buyTurett(0);
		break;
	case 2:
		empire.giveMoney(TURETT1_PRICE);
		empire.buyTurett(1);
		break;
	case 3:
		empire.giveMoney(TURETT2_PRICE);
		empire.buyTurett(0);
		break;
	case 4:
		empire.giveMoney(TURETT2_PRICE);
		empire.buyTurett(1);
		break;
	case 5:
		empire.giveMoney(TURETT3_PRICE);
		empire.buyTurett(0);
		break;
	case 6:
		empire.giveMoney(TURETT3_PRICE);
		empire.buyTurett(1);
		break;
	}
}

void AI::levelUp() {
	switch (m_wave) {
	case 1:
		MeleeFighter1({ 0,0 }, 0).addLevel();
		break;
	case 2:
		RangeFighter1({ 0,0 }, 0).addLevel();
		break;
	case 3:
		RangeFighter2({ 0,0 }, 0).addLevel();
		break;
	case 4:
		KiteBalloon({ 0,0 }, 0).addLevel();
		break;
	case 5:
		RangeFighter3({ 0,0 }, 0).addLevel();
		break;
	case 6:
		RangeFighter4({ 0,0 }, 0).addLevel();
		break;
	}
}