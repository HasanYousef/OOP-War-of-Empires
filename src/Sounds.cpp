#pragma once 

#include "Sounds.h"

Sounds& Sounds::instance() {
	static Sounds inst;
	return inst;
}

std::shared_ptr <sf::Sound> Sounds::getSound(SoundType type) {
	return m_sounds[int(type)];
}

Sounds::Sounds() {
	for (int i = 0; i <= NUM_OF_SOUNDS; i++) {
		m_buffers.push_back(std::make_shared<sf::SoundBuffer>());
		m_sounds.push_back(std::make_shared<sf::Sound>());
	}

	m_buffers[int(SoundType::MenuMusic)]->loadFromFile("menu-music.wav");
	m_sounds[int(SoundType::MenuMusic)]->setBuffer(*m_buffers[int(SoundType::MenuMusic)]);

	m_buffers[int(SoundType::InGameMusic)]->loadFromFile("in-game-music.wav");
	m_sounds[int(SoundType::InGameMusic)]->setBuffer(*m_buffers[int(SoundType::InGameMusic)]);
}