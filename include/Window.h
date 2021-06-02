#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class Window {
public:
	static Window& instance();
	std::shared_ptr<sf::RenderWindow> get_window();
	sf::Vector2i get_size();

private:
	Window();

	std::shared_ptr <sf::RenderWindow> m_window;
	sf::Vector2i m_size;
};