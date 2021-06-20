#pragma once

#include "Match.h"

Match::Match() : m_playerEmpire(LEFT_TEAM), m_enemyEmpire(RIGHT_TEAM) {}

void Match::run() {
	sf::Event event;
	sf::Clock clock;
	sf::Time time;
	float deltaTime = 0;
	std::shared_ptr<sf::RenderWindow> window = Window::instance().get_window();

	std::shared_ptr<sf::Sound> music = Sounds::instance().getSound(SoundType::InGameMusic);
	music->play();
	music->setLoop(true);

	bool pressed = false;
	sf::Vector2f location;

	m_enemyEmpire.addFighter(std::make_shared<MeleeFighter2>
		(sf::Vector2f(1920, 927), RIGHT_TEAM, 100, 10 * 2, 30)); // %#$%@#%#@$%$%^$%#@$#@%#@$%
	m_enemyEmpire.addKiteBalloon();
	m_playerEmpire.addKiteBalloon();

	while (window->isOpen()) {
		deltaTime = clock.restart().asSeconds();
		window->pollEvent(event);
		draw_world(deltaTime);

		// checking actions done in the game's window
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			pressed = true;
			location = window->mapPixelToCoords(
				{ event.mouseButton.x, event.mouseButton.y }
			);
			break;
		case sf::Event::MouseButtonReleased:
			if (pressed) {
				buyFighter(location);
				pressed = false;
			}
			break;
		}


		// We move the fighters 
		m_playerEmpire.moveFighters(m_enemyEmpire.getCastle(), m_enemyEmpire.getFirstFighter());
		m_enemyEmpire.moveFighters(m_playerEmpire.getCastle(), m_playerEmpire.getFirstFighter());
		m_enemyEmpire.moveKiteBalloon();
		m_playerEmpire.moveKiteBalloon();
		// we let the fighters attack each others
		m_playerEmpire.attackFighters(m_enemyEmpire.getCastle(), m_enemyEmpire.getFirstFighter());
		m_enemyEmpire.attackFighters(m_playerEmpire.getCastle(), m_playerEmpire.getFirstFighter());
		// handle kite attack actions
		m_playerEmpire.getLayedBomb();
		m_playerEmpire.getSentBullet();
		m_playerEmpire.moveAirUnites();
		m_playerEmpire.colliedAirUnites(m_enemyEmpire.getFighters(), m_floor.get_position());
		m_enemyEmpire.getLayedBomb();
		m_enemyEmpire.getSentBullet();
		m_enemyEmpire.moveAirUnites();
		m_enemyEmpire.colliedAirUnites(m_playerEmpire.getFighters(), m_floor.get_position());
		// collect the dead
		m_playerEmpire.collectDead();
		m_enemyEmpire.collectDead();
		//check if someone get lost
		if (m_enemyEmpire.ifGetOccupied()) {
			// allies win
			std::cout << "*********************************\n\n            you win            \n\n*********************************\n";
			window->close();
			break;
		}
		else if (m_playerEmpire.ifGetOccupied()) {
			// allies lose
			std::cout << "*********************************\n\n            you lose            \n\n*********************************\n";
			window->close();
			break;
		}
		m_UI.update(m_playerEmpire.getMoney(), m_playerEmpire.getCastle()->getHealth(), m_enemyEmpire.getCastle()->getHealth());
	}
}

void Match::draw_world(float delta) {
	Window::instance().get_window()->clear();

	m_background.draw(0);
	m_floor.draw(0);
	m_UI.draw();
	m_playerEmpire.draw(delta);
	m_enemyEmpire.draw(delta);

	Window::instance().get_window()->display();
}

void Match::buyFighter(const sf::Vector2f& pos) {
	sf::Vector2f spawnPos(0, 927);

	switch (m_UI.handle_click(pos)) {
	case FighterType::Tank1:
		if (m_playerEmpire.getMoney() >= TANK1) {
			m_playerEmpire.addFighter(std::make_shared<MeleeFighter1>
				(spawnPos, LEFT_TEAM, 100, 10, 30));
			m_playerEmpire.pay(TANK1);
		}
		break;
	case FighterType::Tank2:
		if (m_playerEmpire.getMoney() >= TANK2) {
			m_playerEmpire.addFighter(std::make_shared<MeleeFighter2>
				(spawnPos, LEFT_TEAM, 100 * 1.5, 10 * 1.5, 30));
			m_playerEmpire.pay(TANK2);
		}
		break;
	case FighterType::Shooter1:
		if (m_playerEmpire.getMoney() >= SHOOTER1) {
			m_playerEmpire.addFighter(std::make_shared<RangeFighter1>
				(spawnPos, LEFT_TEAM, 100, 10, 30));
			m_playerEmpire.pay(SHOOTER1);
		}
		break;
	case FighterType::Shooter2:
		if (m_playerEmpire.getMoney() >= SHOOTER2) {
			m_playerEmpire.addFighter(std::make_shared<RangeFighter2>
				(spawnPos, LEFT_TEAM, 100, 10 * 2, 30));
			m_playerEmpire.pay(SHOOTER2);
		}
		break;
	case FighterType::Shooter3:
		if (m_playerEmpire.getMoney() >= SHOOTER3) {
			m_playerEmpire.addFighter(std::make_shared<RangeFighter3>
				(spawnPos, LEFT_TEAM, 100, 10 * 3, 30));
			m_playerEmpire.pay(SHOOTER3);
		}
		break;
	case FighterType::Tank3:
		if (m_playerEmpire.getMoney() >= TANK3) {
			m_playerEmpire.addFighter(std::make_shared<RangeFighter4>
				(spawnPos, LEFT_TEAM, 100 * 4, 10 * 5, 30));
			m_playerEmpire.pay(TANK3);
		}
		break;
	default:
		break;
	}
}