#include "Menu.h"

void Menu::run() {
	sf::Event event;
	sf::Clock clock;
	sf::Time time;
	std::shared_ptr<sf::RenderWindow> window = Window::instance().getWindow();

	std::shared_ptr<sf::Sound> music = Sounds::instance().getSound(SoundType::MenuMusic);
	music->play();
	music->setLoop(true);

	while (window->isOpen()) {
		time = clock.getElapsedTime();
		window->pollEvent(event);
		draw(window);
		// checking actions done in the game's window
		switch (event.type) {
		case sf::Event::Closed:
			window->close();
			break;
		// handle mouse click
		case sf::Event::MouseButtonReleased:
			auto location = window->mapPixelToCoords(
				{ event.mouseButton.x, event.mouseButton.y }
			);
			if (m_exitGameButton.handleClick(location)) {
				window->close();
				break;
			}
			if (m_startButton.handleClick(location)) {
				music->stop();
				return;
			}
		}
	}
}

void Menu::draw(std::shared_ptr<sf::RenderWindow> window) {
	window->clear();

	m_background.draw();
	m_startButton.draw();
	m_exitGameButton.draw();

	window->display();
}