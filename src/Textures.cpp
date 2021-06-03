#pragma once 

#include "Textures.h"

Textures& Textures::instance() {
	static Textures inst;
	return inst;
}

std::shared_ptr<sf::Texture> Textures::get_ui_texture(UITexture type) const {
	return m_uiTextures[type];
}

std::shared_ptr<sf::Texture> Textures::get_animation_texture(WorldObjectType objType,
	AnimationType animType, int frame) const {
	
}

Textures::Textures() {
	load_ui_textures();
}

void Textures::load_ui_textures() {
	for (int i = 0; i < NUM_OF_UI_TEXTURES; i++) {
		std::shared_ptr ptr = std::make_shared<sf::Texture>();
		m_uiTextures.push_back(ptr);
	}
	m_uiTextures[UITexture::StartButton]->loadFromFile("StartButton.png");
	m_uiTextures[UITexture::SettingsButton]->loadFromFile("SettingsButton.png");
	m_uiTextures[UITexture::ExitGameButton]->loadFromFile("ExitGameButton.png");
}