#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class Window {
public:
	static Window& instance();
	std::shared_ptr<sf::RenderWindow> getWindow();

private:
	Window();

	std::shared_ptr <sf::RenderWindow> m_window;
};