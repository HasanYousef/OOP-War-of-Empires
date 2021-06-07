#pragma once

#include <Empire.h>

void Empire::draw() const {
	for (std::shared_ptr <LiveAnimatedObject> f : m_fighters) {
		(Window::instance().get_window())->draw(f->create());
	}
}

void Empire::addFighter(LiveAnimatedObject& fighter) {
	m_fighters.push_front(fighter);
}

void Empire::moveFighters(sf::Vector2f &castlePoints, sf::Vector2f &lastFighter) {
	if(!(castlePoints == m_fighters.back().get()->create().get_position() || 
		m_fighters.back().get()->create().get_position() == lastFighter)) {
		for (auto& fighter : m_fighters) {
			//fighter.get()->move(); /****** ADD MOVE FUNCTION ON LiveAnimatedObject ******/
		}
	}
}

void Empire::draw(std::shared_ptr<sf::RenderWindow> window) {
	m_castle.draw(window);
	for (auto& fighter : m_fighters) {
		fighter.get()->draw(window);
	}
}

sf::Sprite Empire::getCastle() const{
	return m_castle.create();
}

sf::Sprite Empire::getFirstFighter() const {
	return m_fighters.back().get()->create;
}
