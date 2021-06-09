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
		draw_world(1.0);
		// checking actions done in the game's window
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		}
		//need to add menue of players

		// We move the fighters 
		m_playerEmpire.moveFighters(m_enemyEmpire.getCastle(), m_enemyEmpire.getFirstFighter());
		m_enemyEmpire.moveFighters(m_playerEmpire.getCastle(), m_playerEmpire.getFirstFighter());
		// we let the fighters attack each others
		//m_playerEmpire.attackFighters(*m_enemyEmpire.getCastle(), *m_enemyEmpire.getFirstFighter());
		//m_enemyEmpire.attackFighters(*m_playerEmpire.getCastle(), *m_playerEmpire.getFirstFighter());
		// collect the dead
		m_playerEmpire.collectDead();
		m_enemyEmpire.collectDead();
	}
}

void Match::draw_world(float delta) {
	Window::instance().get_window()->clear();

	m_background.draw();
	m_playerEmpire.draw(delta);
	m_enemyEmpire.draw(delta);

	Window::instance().get_window()->display();
}