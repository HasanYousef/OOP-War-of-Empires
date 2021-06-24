#pragma once

#include "Match.h"
#include "AI.h"

Match::Match() : m_playerEmpire(LEFT_TEAM), m_enemyEmpire(RIGHT_TEAM) {}

bool Match::run() {
	sf::Event event;
	sf::Clock clock;
	sf::Time time;
	float deltaTime = 0;
	std::shared_ptr<sf::RenderWindow> window = Window::instance().getWindow();

	std::shared_ptr<sf::Sound> music = Sounds::instance().getSound(SoundType::InGameMusic);
	music->play();
	music->setLoop(true);

	bool pressed = false;
	sf::Vector2f location;
	AI ai;
	//m_enemyEmpire.giveMoney(500);
	while (window->isOpen()) {
		deltaTime = clock.restart().asSeconds();
		window->pollEvent(event);
		drawWorld(deltaTime);

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

		ai.bot(m_enemyEmpire);

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
		m_playerEmpire.colliedAirUnites(m_enemyEmpire.getFighters(), m_floor.getPosition());
		m_enemyEmpire.getLayedBomb();
		m_enemyEmpire.getSentBullet();
		m_enemyEmpire.moveAirUnites();
		m_enemyEmpire.colliedAirUnites(m_playerEmpire.getFighters(), m_floor.getPosition());
		// collect money of the fully dead
		m_playerEmpire.collectEnemyMoney(m_enemyEmpire.getFighters());
		m_enemyEmpire.collectEnemyMoney(m_playerEmpire.getFighters());
		// collect the dead
		m_playerEmpire.collectDead();
		m_enemyEmpire.collectDead();
		//check if someone get lost
		if (m_enemyEmpire.ifGetOccupied()) {
			music->stop();
			return true;
		}
		else if (m_playerEmpire.ifGetOccupied()) {
			music->stop();
			return false;
		}
		m_UI.update(m_playerEmpire.getMoney(), m_playerEmpire.getCastle()->getHealth(), m_enemyEmpire.getCastle()->getHealth());
	}
}

void Match::drawWorld(float delta) {
	Window::instance().getWindow()->clear();

	m_background.draw(0);
	m_floor.draw(0);
	m_playerEmpire.draw(delta);
	m_enemyEmpire.draw(delta);
	m_UI.draw();

	Window::instance().getWindow()->display();
}

void Match::buyFighter(const sf::Vector2f& pos) {
	sf::Vector2f spawnPos(0, 1080 - 120);

	switch (m_UI.handleClickFighters(pos)) {
	case FighterType::Tank1:
		if (m_playerEmpire.getMoney() >= MELEE_1_WORTH) {
			m_playerEmpire.addFighter(std::make_shared<MeleeFighter1>
				(spawnPos, LEFT_TEAM));
			m_playerEmpire.pay(MELEE_1_WORTH);
		}
		break;
	case FighterType::Tank2:
		if (m_playerEmpire.getMoney() >= MELEE_2_WORTH) {
			m_playerEmpire.addFighter(std::make_shared<MeleeFighter2>
				(spawnPos, LEFT_TEAM));
			m_playerEmpire.pay(MELEE_2_WORTH);
		}
		break;
	case FighterType::Shooter1:
		if (m_playerEmpire.getMoney() >= RANGE_1_WORTH) {
			m_playerEmpire.addFighter(std::make_shared<RangeFighter1>
				(spawnPos, LEFT_TEAM));
			m_playerEmpire.pay(RANGE_1_WORTH);
		}
		break;
	case FighterType::Shooter2:
		if (m_playerEmpire.getMoney() >= RANGE_2_WORTH) {
			m_playerEmpire.addFighter(std::make_shared<RangeFighter2>
				(spawnPos, LEFT_TEAM));
			m_playerEmpire.pay(RANGE_2_WORTH);
		}
		break;
	case FighterType::Shooter3:
		if (m_playerEmpire.getMoney() >= RANGE_3_WORTH) {
			m_playerEmpire.addFighter(std::make_shared<RangeFighter3>
				(spawnPos, LEFT_TEAM));
			m_playerEmpire.pay(RANGE_3_WORTH);
		}
		break;
	case FighterType::Tank3:
		if (m_playerEmpire.getMoney() >= RANGE_4_WORTH) {
			m_playerEmpire.addFighter(std::make_shared<RangeFighter4>
				(spawnPos, LEFT_TEAM));
			m_playerEmpire.pay(RANGE_4_WORTH);
		}
		break;
	default:
		break;
	}

	if (m_UI.handleClickBalloon(pos))
		m_playerEmpire.addKiteBalloon();

	int stand = m_UI.handleClickTuretts(pos);
	if (stand != -1) {
		int type = m_playerEmpire.buyTurett(stand);
		if (type != -1)
			m_UI.setTurettType(stand, type + 1);
	}
}
