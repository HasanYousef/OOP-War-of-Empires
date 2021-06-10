#pragma once

#include <Empire.h>

void Empire::addFighter(std::shared_ptr <Fighter> fighter) {
	m_fighters.push_front(fighter);
}

void Empire::moveFighters(std::shared_ptr <Castle> castle, std::shared_ptr <Fighter> enemyFighter) {
	int fighternum = 0;
	for (auto fighter = m_fighters.begin(); fighter != m_fighters.end(); ++fighter) {
		if (fighternum == m_fighters.size() - 1) {
			fighter->get()->move(NULL, enemyFighter, castle);
		}
		else if(fighternum < m_fighters.size()) {
			try
			{
				auto frontFighter = *std::next(fighter);
				fighter->get()->move(frontFighter, enemyFighter, castle);
			}
			catch (const std::exception&)
			{

			}
			
		}
		fighternum++;
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
			m_money += firstEnemy->getGoldWorth();
			return;
		}
	}
}
*/

void Empire::collectDead() {
	for (auto fighter : m_fighters) {
		if (fighter->fullyDead()) {
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
