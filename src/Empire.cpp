#pragma once

#include <Empire.h>

void Empire::addFighter(std::shared_ptr <Fighter> fighter) {
	m_fighters.push_back(fighter);
}

void Empire::moveFighters(std::shared_ptr <Castle> castle, std::shared_ptr <Fighter> enemyFighter) {
	bool firstFighter = true;
	for (auto fighter = m_fighters.begin(); fighter != m_fighters.end(); ++fighter) {
		if (firstFighter) {
			firstFighter = false;
			fighter->get()->move(NULL, enemyFighter, castle);
		}
		else {
			auto frontFighter = std::next(fighter);
			fighter->get()->move(*frontFighter, enemyFighter, castle);
		}
	}
}

void Empire::draw(float delta) const {
	//m_castle.draw();
	for (auto& fighter : m_fighters) {
		fighter->draw(delta);
	}
}
/*
void Empire::attackFighters(std::shared_ptr <Castle>, std::shared_ptr <Fighter>) {
	for (auto& fighter : m_fighters) {
		fighter->attack(firstEnemy, castle);
		if (firstEnemy.getHealth() <= DIE || castle->getHealth() <= DIE) {
			return;
		}
	}
}
*/

void Empire::collectDead() {
	for (auto fighter : m_fighters) {
		if (fighter->fullyDead()) {
			m_money += fighter->getGoldWorth();
			m_fighters.remove(fighter);
		}
	}
	/*m_fighters.remove_if([](Fighter& fighter) { return 
	(fighter.getHealth() == 0 && fighter.getAnimationType() == AnimationType::Idle)});*/
}

std::shared_ptr <Castle> Empire::getCastle() {
	return m_castle;
}

std::shared_ptr <Fighter> Empire::getFirstFighter() {
	return (m_fighters.size() > 0) ? m_fighters.back() : NULL;

}
