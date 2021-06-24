#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include "macros.h"

class Textures {
public:
	static Textures& instance();
	std::shared_ptr<sf::Texture> getUiTexture(UITexture) const;
	std::shared_ptr<sf::Texture> getWorldObjTexture(WorldObjectType) const;
	int numOfAnimFrames(FighterType, AnimationType) const;
	int numOfGunFireFrames() const;
	std::shared_ptr<sf::Texture> getAnimationTexture(FighterType, AnimationType, int) const;
	std::shared_ptr<sf::Texture> getTurettTexture(TurettType, int) const;
	std::shared_ptr<sf::Font> getFont() const;
	std::shared_ptr<sf::Texture> getGunFireTexture(int) const;
	std::shared_ptr<sf::Texture> getKiteBalloonTexture(int,int) const;
	std::shared_ptr<sf::Texture> getBombTexture(int) const;
	std::shared_ptr<sf::Texture> getExplosionTexture(int, int) const;
	std::shared_ptr<sf::Texture> getBullet() const;

private:
	Textures();
	void loadUiTextures();
	void loadWorldObjTextures();
	void loadAnimTextures();
	void loadTurettsTextures();
	void loadFont();
	void loadGunFireTextures();
	void loadKiteBalloonTextures();
	void loadBombTextures();
	void loadExplosionTextures();

	std::string fighterFileName(FighterType) const;
	std::string animationName(AnimationType anim) const;

	std::vector <std::shared_ptr <sf::Texture>> m_uiTextures;
	std::vector <std::shared_ptr <sf::Texture>> m_worldObjectTextures;
	// 3D vector: m_animations[enum FighterType][enum AnimationType][int Frame]
	std::vector <std::vector <std::vector <std::shared_ptr <sf::Texture>>>> m_animations;
	std::vector <std::vector <std::shared_ptr <sf::Texture>>> m_turetts;
	std::shared_ptr<sf::Font> m_font;
	std::vector <std::shared_ptr <sf::Texture>> m_gunFireAnimations;
	std::vector <std::vector <std::shared_ptr <sf::Texture>>> m_kiteBalloonAnimations;
	std::vector <std::shared_ptr <sf::Texture>> m_bombs;
	std::vector <std::vector <std::shared_ptr <sf::Texture>>> m_explotionAnimation;
	std::shared_ptr <sf::Texture > m_bullet;
};