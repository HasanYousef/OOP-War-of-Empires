#pragma once

#include <SFML/Audio.hpp>
#include <vector>

#include "macros.h"

class Sounds {
public:
	static Sounds& instance();
	std::shared_ptr <sf::Sound> getSound(SoundType);

private:
	Sounds();
	std::vector < std::shared_ptr <sf::Sound>> m_sounds;
	std::vector < std::shared_ptr <sf::SoundBuffer>> m_buffers;
};