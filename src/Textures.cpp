#pragma once 

#include "Textures.h"

Textures& Textures::instance() {
	static Textures inst;
	return inst;
}

std::shared_ptr<sf::Texture> Textures::get_background() {
	return m_background;
}

Textures::Textures() {
	m_background = std::make_shared<sf::Texture>();
	m_background->loadFromFile("background.jpg");
}