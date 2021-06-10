#pragma once

#include "Match.h"

void Match::run() {
	sf::Event event;
	sf::Clock clock;
	sf::Time time;
	float deltaTime = 0;
	std::shared_ptr<sf::RenderWindow> window = Window::instance().get_window();

	std::shared_ptr<sf::Sound> music = Sounds::instance().getSound(SoundType::InGameMusic);
	music->play();
	music->setLoop(true);

	while (window->isOpen()) {
		deltaTime = clock.restart().asSeconds();
		window->pollEvent(event);
		draw_world(deltaTime);
		// checking actions done in the game's window
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			m_enemyEmpire.addFighter((std::make_shared<MeleeFighter>
				(sf::Vector2f(100 + 1090, 927), false, 100, 10, 10)));
			m_playerEmpire.addFighter((std::make_shared<MeleeFighter>
				(sf::Vector2f(100 , 927), true, 100, 10, 10)));
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
	m_floor.draw(0);
	m_playerEmpire.draw(delta);
	m_enemyEmpire.draw(delta);

	Window::instance().get_window()->display();
}