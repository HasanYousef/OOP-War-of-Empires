#pragma once

#include "AI.h"

void AI::bot(std::shared_ptr<Empire> empire) {
	int spawn = 0;
	float timeWait = m_level * 2.5;
	m_levelTime = m_clock.getElapsedTime();
	//change num of soilder every 120 sec
	if (m_levelTime.asSeconds() == TWOMINUTES) {
		m_level++;
		if (m_level > 2) {
			m_level = 0;
		}
		m_clock.restart();
	}
	// buy Turret if we can
	if ( true /* ADD IF CAN BY TURRET */) {
		m_level++;
		//by stronget turrent
	}

	// CHECK IF THERE ARE A TURRET TO DEVOLP (LEVEL UP)

	sf::Vector2f spawnPos(1920, 927);
	// buy tanks fighters
	if (empire->getFightersNum() < (4 + (m_level * 2))) {
		// buy a TANK VEHICLE
		if (m_tankInFront /* && can by a tank */ ) {
			m_tankInFront = false;
			// ADD A TANK VEHICLE
		}
		if (empire->getMoney() >= TANK2) {
			empire->addFighter(std::make_shared<MeleeFighter2>
				(spawnPos, LEFT_TEAM, 100 * 1.5, 10 * 1.5, 30));
			empire->pay(TANK2);
		}
		else if (empire->getMoney() >= TANK1) {
			empire->addFighter(std::make_shared<MeleeFighter1>
				(spawnPos, LEFT_TEAM, 100, 10, 30));
			empire->pay(TANK1);
		}
		// by a shooters
		while (spawn < 2) {
			if (empire->getMoney() >= SHOOTER3) {
				empire->addFighter(std::make_shared<RangeFighter3>
					(spawnPos, LEFT_TEAM, 100, 10 * 3, 30));
				empire->pay(SHOOTER3);
			}
			else if (empire->getMoney() >= SHOOTER2) {
				empire->addFighter(std::make_shared<RangeFighter2>
					(spawnPos, LEFT_TEAM, 100, 10 * 2, 30));
				empire->pay(SHOOTER2);
			}
			else if (empire->getMoney() >= SHOOTER1) {
				empire->addFighter(std::make_shared<RangeFighter1>
					(spawnPos, LEFT_TEAM, 100, 10, 30));
				empire->pay(SHOOTER1);
			}
			spawn++;
		}
		// buy a TANK VEHICLE
		if (!(m_tankInFront) /* && can by a tank */) {
			m_tankInFront = true;
			// ADD A TANK VEHICLE
		}
	}
}
