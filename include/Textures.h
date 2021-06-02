#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

class Textures {
public:
	static Textures& instance();
	std::shared_ptr<sf::Texture> get_background();

private:
	Textures();

	std::shared_ptr <sf::Texture> m_background;
};