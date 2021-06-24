#pragma once 

#include "Window.h"

Window& Window::instance() {
	static Window inst;
	return inst;
}

std::shared_ptr<sf::RenderWindow> Window::getWindow() {
	return m_window;
}

Window::Window() {
	m_window = std::make_shared<sf::RenderWindow>();
	m_window->create(sf::VideoMode(1920, 1080), "War of Empires", sf::Style::Close);
}