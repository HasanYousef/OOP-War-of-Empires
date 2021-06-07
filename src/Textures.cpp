#pragma once 

#include "Textures.h"

Textures& Textures::instance() {
	static Textures inst;
	return inst;
}

std::shared_ptr<sf::Texture> Textures::get_ui_texture(UITexture type) {
	return m_uiTextures[int(type)];
}

std::shared_ptr<sf::Texture> Textures::get_animation_texture(WorldObjectType objType,
	AnimationType animType, int frame) {
	return m_animations[0][0];
}

Textures::Textures() {
	load_ui_textures();
}

void Textures::load_ui_textures() {
	for (int i = 0; i <= NUM_OF_UI_TEXTURES; i++) {
		std::shared_ptr ptr = std::make_shared<sf::Texture>();
		m_uiTextures.push_back(ptr);
	}

	m_uiTextures[int(UITexture::MenuBackground)]->loadFromFile("menu-background.png");
	m_uiTextures[int(UITexture::MatchBackground)]->loadFromFile("match-background.png");
	m_uiTextures[int(UITexture::StartButton)]->loadFromFile("start-button.png");
	m_uiTextures[int(UITexture::ExitGameButton)]->loadFromFile("exit-game-button.png");
}