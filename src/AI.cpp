#pragma once

#include "AI.h"

void AI::bot(Empire& empire) {
	int spawn = 0;
	m_levelTime = m_clock.getElapsedTime();
	//change num of soilder every 120 sec
	if (m_levelTime.asSeconds() >= WAVE) {
		m_level++;
		if (m_level > 2) {
			m_level = 0;
		}
		empire.giveMoney(500);
		m_clock.restart();
		empire.addKiteBalloon();
	}
	// buy Turret if we can
	if (empire.getMoney() >= TURETT1_PRICE) {
		if (m_upTurretStand) {
			m_upTurretStand = false;
			empire.buyTurett(0);
		}
		else {
			m_upTurretStand = true;
			empire.buyTurett(1);
		}
		m_score += 100;
	}
	sf::Vector2f spawnPos(empire.getCastle()->get_object_team() ? 20 : 1920, 927);
	// buy tanks fighters
	if (empire.getFightersNum() < (4 + (m_level * 2))) {
		// buy a TANK VEHICLE
		if (empire.getMoney() >= MELEE_2_WORTH) {
			empire.addFighter(std::make_shared<MeleeFighter2>
				(spawnPos, empire.getCastle()->get_object_team()));
			empire.pay(MELEE_2_WORTH);
		}
		else if (empire.getMoney() >= MELEE_1_WORTH) {
			empire.addFighter(std::make_shared<MeleeFighter1>
				(spawnPos, empire.getCastle()->get_object_team()));
			empire.pay(MELEE_1_WORTH);
		}
		// by a shooters
		while (spawn < 2) {
			if (empire.getMoney() >= RANGE_3_WORTH) {
				empire.addFighter(std::make_shared<RangeFighter3>
					(spawnPos, empire.getCastle()->get_object_team()));
				empire.pay(RANGE_3_WORTH);
			}
			else if (empire.getMoney() >= RANGE_2_WORTH) {
				empire.addFighter(std::make_shared<RangeFighter2>
					(spawnPos, empire.getCastle()->get_object_team()));
				empire.pay(RANGE_2_WORTH);
			}
			else if (empire.getMoney() >= RANGE_1_WORTH) {
				empire.addFighter(std::make_shared<RangeFighter1>
					(spawnPos, empire.getCastle()->get_object_team()));
				empire.pay(RANGE_1_WORTH);
			}
			spawn++;
		}

		// buy a TANK VEHICLE
		if (empire.getMoney() >= RANGE_4_WORTH) {
			empire.addFighter(std::make_shared<RangeFighter4>
				(spawnPos, empire.getCastle()->get_object_team()));
			empire.pay(RANGE_4_WORTH);
		}
	}
	if (empire.getFightersNum() == 0 && m_levelTime.asSeconds() < (WAVE / 2)) {
		empire.giveMoney(500);
	}
}
