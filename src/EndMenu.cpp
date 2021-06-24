#include "EndMenu.h"

void EndMenu::run(bool won) {
	sf::Event event;
	sf::Clock clock;
	sf::Time time;
	std::shared_ptr<sf::RenderWindow> window = Window::instance().getWindow();

	Sounds::instance().getSound(SoundType::EndMusic)->play();

	while (window->isOpen()) {
		time = clock.getElapsedTime();
		window->pollEvent(event);
		draw(window, won);
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
			return;
		}
	}
}

void EndMenu::draw(std::shared_ptr<sf::RenderWindow> window, bool won) {
	window->clear();
	auto background = sf::Sprite(*Textures::instance().getUiTexture(won ? UITexture::WonBackground : UITexture::LostBackground));
	Window::instance().getWindow()->draw(background);
	window->display();
}