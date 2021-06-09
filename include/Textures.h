#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "macros.h"

class Textures {
public:
	static Textures& instance();
	std::shared_ptr<sf::Texture> get_ui_texture(UITexture) const;
	int num_of_anim_frames(FighterType, AnimationType) const;
	std::shared_ptr<sf::Texture> get_animation_texture(FighterType, AnimationType, int) const;

private:
	Textures();
	void load_ui_textures();

	std::vector <std::shared_ptr <sf::Texture>> m_uiTextures;
	// 3D vector: m_animations[enum FighterType][enum AnimationType][int Frame]
	std::vector <std::vector <std::vector <std::shared_ptr <sf::Texture>>>> m_animations;
};