#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "macros.h"

class Textures {
public:
	static Textures& instance();
	std::shared_ptr<sf::Texture> get_ui_texture(UITexture) const;
	std::shared_ptr<sf::Texture> get_animation_texture(WorldObjectType, AnimationType, int) const;

private:
	Textures();
	void load_ui_textures();

	std::vector <std::shared_ptr <sf::Texture>> m_uiTextures;
	std::vector <std::vector <std::shared_ptr <sf::Texture>>> m_animations;
};