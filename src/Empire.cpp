#pragma once

#include <Empire.h>

void Empire::draw() const {
	for (std::shared_ptr <Fighter> f : m_fighters) {
		(Window::instance().get_window())->draw(f->create());
	}
}

void Empire::addFighter(Fighter& fighter) {
	m_fighters.push_back(fighter);
}

void Empire::moveFighters(Castle &castle, Fighter &fighter) {
	bool firstFighter = true;
	for (auto& fighter : m_fighters) {
		if (firstFighter) {
			firstFighter = false;
			fighter.get()->move(castle, fighter, NULL);
		}
		else {
			auto frontFighter = fighter;
			fighter.get()->move(castle, fighter, frontFighter.get());
		}
	}
}

void Empire::draw(std::shared_ptr<sf::RenderWindow> window) {
	m_castle.draw();
	for (auto& fighter : m_fighters) {
		fighter.get()->draw();
	}
}

void Empire::attackFighters(Castle &castle,Fighter& firstEnemy) {
	for (auto& fighter : m_fighters) {
		fighter.get()->attack(castle, firstEnemy);
		if (firstEnemy->getHealth() <= DIE || castle->getHealth() <= DIE) {
			return;
		}
	}
}

void Empire::collectDead() {
	for (auto& fighter : m_fighters) {
		if (fighter.get().fullyDead()) {
			m_money += fighter.getGoldWorth();
			m_fighters.remove(fighter);
		}
	}
	/*m_fighters.remove_if([](Fighter& fighter) { return 
	(fighter.getHealth() == 0 && fighter.getAnimationType() == AnimationType::Idle)});*/
}

Castle Empire::getCastle() {
	return m_castle.get();
}

Fighter Empire::getFirstFighter() {
	return m_fighters.back().get();
}
