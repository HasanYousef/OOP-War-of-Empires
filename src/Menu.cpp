#include "Menu.h"

void Menu::run() {
	sf::Event event;
	sf::Clock clock;
	sf::Time time;
	std::shared_ptr<sf::RenderWindow> window = Window::instance().get_window();
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
			handle_click(location);
		}
	}
}

void Menu::draw(std::shared_ptr<sf::RenderWindow> window) {
	window->clear();
	draw_background(window);
	window->display();
}

void Menu::draw_background(std::shared_ptr<sf::RenderWindow> window) {
	auto background = Textures::instance().get_background();
	sf::Sprite result = sf::Sprite(*background);

	int windowHeight = Window::instance().get_size().y;
	auto spriteHeight = result.getLocalBounds().height;
	result.setScale(
		windowHeight / spriteHeight,
		windowHeight / spriteHeight);

	window->draw(result);
}