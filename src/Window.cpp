#pragma once 

#include "Window.h"

Window& Window::instance() {
	static Window inst;
	return inst;
}

std::shared_ptr<sf::RenderWindow> Window::get_window() {
	return m_window;
}

sf::Vector2i Window::get_size() {
	return m_size;
}

Window::Window() {
	m_size = {1600, 900};
	m_window = std::make_shared<sf::RenderWindow>();
	m_window->create(sf::VideoMode(m_size.x, m_size.y), "Robots of War", sf::Style::Close);
}