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
		// We move the fighters 
		/*playerEmpire.moveFighters(enemyEmpire.getCastle().getPosition(),
			enemyEmpire.getFirstFighter().getPosition());
		enemyEmpire.moveFighters(playerEmpire.getCastle().getPosition(),
			playerEmpire.getFirstFighter().getPosition());
			*/
	}
}

void Match::draw_world(std::shared_ptr<sf::RenderWindow> window) {
	window->clear();

	m_background.draw();
	//playerEmpire.draw(window);
	//enemyEmpire.draw(window);

	window->display();
}