#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "macros.h"

class Textures {
public:
	static Textures& instance();
	std::shared_ptr<sf::Texture> get_ui_texture(UITexture);
	std::shared_ptr<sf::Texture> get_animation_texture(WorldObjectType, AnimationType, int);

private:
	Textures();
	void load_ui_textures();

	std::vector <std::shared_ptr <sf::Texture>> m_uiTextures;
	std::vector <std::vector <std::shared_ptr <sf::Texture>>> m_animations;
};