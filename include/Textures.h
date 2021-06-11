#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "macros.h"

class Textures {
public:
	static Textures& instance();
	std::shared_ptr<sf::Texture> get_ui_texture(UITexture) const;
	std::shared_ptr<sf::Texture> get_world_obj_texture(WorldObjectType) const;
	int num_of_anim_frames(FighterType, AnimationType) const;
	std::shared_ptr<sf::Texture> get_animation_texture(FighterType, AnimationType, int) const;
	std::string animation_name(AnimationType anim) const;

private:
	Textures();
	void load_ui_textures();
	void load_world_obj_textures();
	void load_anim_textures();
	std::string fighter_file_name(FighterType) const;

	std::vector <std::shared_ptr <sf::Texture>> m_uiTextures;
	std::vector <std::shared_ptr <sf::Texture>> m_worldObjectTextures;
	// 3D vector: m_animations[enum FighterType][enum AnimationType][int Frame]
	std::vector <std::vector <std::vector <std::shared_ptr <sf::Texture>>>> m_animations;
};