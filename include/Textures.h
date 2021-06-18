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
	int num_of_gun_fire_frames() const;
	std::shared_ptr<sf::Texture> get_animation_texture(FighterType, AnimationType, int) const;
	std::shared_ptr<sf::Texture> get_turett_texture(TurettType, int) const;
	std::shared_ptr<sf::Font> get_font() const;
	std::shared_ptr<sf::Texture> get_gun_fire_texture(int) const;
	std::shared_ptr<sf::Texture> get_bullet() const;

private:
	Textures();
	void load_ui_textures();
	void load_world_obj_textures();
	void load_anim_textures();
	void load_turetts_texturs();
	void load_font();
	void load_gun_fire_textures();
	std::string fighter_file_name(FighterType) const;
	std::string animation_name(AnimationType anim) const;

	std::vector <std::shared_ptr <sf::Texture>> m_uiTextures;
	std::vector <std::shared_ptr <sf::Texture>> m_worldObjectTextures;
	// 3D vector: m_animations[enum FighterType][enum AnimationType][int Frame]
	std::vector <std::vector <std::vector <std::shared_ptr <sf::Texture>>>> m_animations;
	std::vector <std::vector <std::shared_ptr <sf::Texture>>> m_turetts;
	std::shared_ptr<sf::Font> m_font;
	std::vector <std::shared_ptr <sf::Texture>> m_gunFireAnimations;
	std::shared_ptr <sf::Texture > m_bullet;
};