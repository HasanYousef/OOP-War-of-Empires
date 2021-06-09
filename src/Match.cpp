#pragma once

#include "Match.h"

void Match::run() {
	sf::Event event;
	sf::Clock clock;
	sf::Time time;
	std::shared_ptr<sf::RenderWindow> window = Window::instance().get_window();

	std::shared_ptr<sf::Sound> music = Sounds::instance().getSound(SoundType::InGameMusic);
	music->play();
	music->setLoop(true);

	while (window->isOpen()) {
		time = clock.getElapsedTime();
		window->pollEvent(event);
		draw_world(window);
		// checking actions done in the game's window
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		}
		//need to add menue of players

		//we get the castles and the front fighter os the empires
		auto castlePlayer = m_playerEmpire.getCastle();
		auto castleEnemy = m_enemyEmpire.getCastle();
		auto firstFighterEnemy = m_enemyEmpire.getFirstFighter();
		auto firstFighterPlayer = m_playerEmpire.getFirstFighter();
		// We move the fighters 
		m_playerEmpire.moveFighters(castleEnemy, firstFighterEnemy);
		m_enemyEmpire.moveFighters(castlePlayer, firstFighterPlayer);
		// we let the fighters attack each others
		m_playerEmpire.attackFighters(castleEnemy, firstFighterEnemy);
		m_enemyEmpire.attackFighters(castlePlayer, firstFighterPlayer);
		// collect the dead
		m_playerEmpire.collectDead();
		m_enemyEmpire.collectDead();
	}
}

void Match::draw_world(std::shared_ptr<sf::RenderWindow> window) {
	window->clear();

	m_background.draw();
	m_playerEmpire.draw(window);
	m_enemyEmpire.draw(window);

	window->display();
}