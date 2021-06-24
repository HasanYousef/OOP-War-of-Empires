#pragma once 

#include "Textures.h"

Textures& Textures::instance() {
	static Textures inst;
	return inst;
}

std::shared_ptr<sf::Texture> Textures::getUiTexture(UITexture type) const {
	return m_uiTextures[int(type)];
}

std::shared_ptr<sf::Texture> Textures::getWorldObjTexture(WorldObjectType type) const {
	return m_worldObjectTextures[int(type)];
}

std::shared_ptr<sf::Texture> Textures::getAnimationTexture(FighterType fighter,
	AnimationType animType, int frame) const {
	return m_animations[int(fighter)][int(animType)][frame];
}

std::shared_ptr<sf::Texture> Textures::getTurettTexture(TurettType turett, int frame) const {
	return m_turetts[int(turett)][frame];
}

int Textures::numOfAnimFrames(FighterType fighter, AnimationType animType) const {
	return m_animations[int(fighter)][int(animType)].size();
}

int Textures::numOfGunFireFrames() const {
	return int(m_gunFireAnimations.size());
}

std::shared_ptr<sf::Font> Textures::getFont() const {
	return m_font;
}

std::shared_ptr<sf::Texture> Textures::getGunFireTexture(int frame) const {
	return m_gunFireAnimations[frame];
}

std::shared_ptr<sf::Texture> Textures::getKiteBalloonTexture(int kiteLevel, int frame) const {
	return m_kiteBalloonAnimations[size_t(kiteLevel) -1][frame];
}

std::shared_ptr<sf::Texture> Textures::getBombTexture(int module) const {
	return m_bombs[size_t(module)-1];
}
std::shared_ptr<sf::Texture> Textures::getExplosionTexture(int kiteLevel, int frame) const {
	return m_explotionAnimation[size_t(kiteLevel) - 1][frame];
}

Textures::Textures() {
	loadUiTextures();
	loadWorldObjTextures();
	loadAnimTextures();
	loadTurettsTextures();
	loadFont();
	loadGunFireTextures();
	loadKiteBalloonTextures();
	loadBombTextures();
	loadExplosionTextures();

	m_bullet = std::make_shared<sf::Texture>();
	m_bullet->loadFromFile("bullet.png");
}

void Textures::loadUiTextures() {
	for (int i = 0; i <= NUM_OF_UI_TEXTURES; i++) {
		std::shared_ptr ptr = std::make_shared<sf::Texture>();
		m_uiTextures.push_back(ptr);
	}

	m_uiTextures[int(UITexture::MenuBackground)]->loadFromFile("menu-background.png");
	m_uiTextures[int(UITexture::StartButton)]->loadFromFile("start-button.png");
	m_uiTextures[int(UITexture::ExitGameButton)]->loadFromFile("exit-game-button.png");
	m_uiTextures[int(UITexture::ActiveButton)]->loadFromFile("active-button.png");
	m_uiTextures[int(UITexture::UnactiveButton)]->loadFromFile("unactive-button.png");
	m_uiTextures[int(UITexture::BuyWorldObjectBackground)]->loadFromFile("buy-world-object-background.png");
	m_uiTextures[int(UITexture::CastleHealthbar)]->loadFromFile("castle-healthbar.png");
	m_uiTextures[int(UITexture::CastleHealthbarBackground)]->loadFromFile("castle-healthbar-background.png");
	m_uiTextures[int(UITexture::WonBackground)]->loadFromFile("wonBackground.png");
	m_uiTextures[int(UITexture::LostBackground)]->loadFromFile("lostBackground.png");
}

void Textures::loadWorldObjTextures() {
	for (int i = 0; i <= NUM_OF_WORLD_OBJECT_TYPES; i++) {
		std::shared_ptr ptr = std::make_shared<sf::Texture>();
		m_worldObjectTextures.push_back(ptr);
	}

	m_worldObjectTextures[int(WorldObjectType::MatchBackground)]->loadFromFile("match-background.png");
	m_worldObjectTextures[int(WorldObjectType::Floor)]->loadFromFile("floor-texture.png");
	m_worldObjectTextures[int(WorldObjectType::Castle)]->loadFromFile("castle-texture.png");
}

void Textures::loadAnimTextures() {
	for (int i = 0; i < NUM_OF_FIGHTER_TYPES; i++) {
		std::vector <std::vector <std::shared_ptr <sf::Texture>>> fighter;
		FighterType fighterType = FighterType(i);

		for (int j = 0; j < NUM_OF_ANIMATION_TYPES; j++) {
			std::string fighterFName = fighterFileName(fighterType);
			AnimationType animationType = AnimationType(j);
			// just the Tank1 and the Tank2 fighters have Attack animations
			if (animationType == AnimationType::Attack)
				if (fighterType != FighterType::Tank1 && fighterType != FighterType::Tank2)
					break;
			if (fighterType == FighterType::Tank3 && animationType == AnimationType::Attack)
				break;

			std::vector <std::shared_ptr <sf::Texture>> anim;
			fighterFName += animationName(animationType);
			int frame = 0;
			while (true) {
				anim.push_back(std::make_shared<sf::Texture>());
				if (!anim[frame]->loadFromFile(fighterFName + std::to_string(frame) + ".png")) {
					anim.pop_back();
					break;		// stop reading more frames when there is no more
				}
				frame++;
			}

			fighter.push_back(anim);
		}
		m_animations.push_back(fighter);
	}
}

void Textures::loadTurettsTextures() {
	for (int i = 0; i < NUM_OF_TURETT_TYPES; i++) {
		std::vector <std::shared_ptr <sf::Texture>> turett;
		TurettType turettType = TurettType(i);

		std::string turettFileName = "skeleton";
		turettFileName += (std::to_string(i + 1) + "-Shoot_");
		int frame = 0;
		while (true) {
			turett.push_back(std::make_shared<sf::Texture>());
			if (!turett[frame]->loadFromFile(turettFileName + std::to_string(frame) + ".png")) {
				turett.pop_back();
				break;		// stop reading more frames when there is no more
			}
			frame++;
		}

		m_turetts.push_back(turett);
	}
}

void Textures::loadFont() {
	m_font = std::make_shared<sf::Font>();
	m_font->loadFromFile("font.ttf");
}

void Textures::loadGunFireTextures() {
	std::string fighterFileName("skeleton-fire-animation_");
	int frame = 0;
	while (true) {
		m_gunFireAnimations.push_back(std::make_shared<sf::Texture>());
		if (!m_gunFireAnimations[frame]->loadFromFile(fighterFileName + std::to_string(frame) + ".png")) {
			m_gunFireAnimations.pop_back();
			break;		// stop reading more frames when there is no more
		}
		frame++;
	}
}

void Textures::loadKiteBalloonTextures() {
	std::string kitesFileName("skeleton-kite");
	int level = 1;
	while (level <= 2) {
		std::vector <std::shared_ptr <sf::Texture>> kiteBalloonAnimation;
		int frame = 0;
		std::string temp = kitesFileName + std::to_string(level) + "-Moving_";

		while (true) {
			kiteBalloonAnimation.push_back(std::make_shared<sf::Texture>());
			if (!kiteBalloonAnimation[frame]->loadFromFile(temp + std::to_string(frame) + ".png")) {
				kiteBalloonAnimation.pop_back();
				break;		// stop reading more frames when there is no more
			}
			frame++;
		}
		m_kiteBalloonAnimations.push_back(kiteBalloonAnimation);
		level++;
	}
}

void Textures::loadBombTextures() {
	std::string fighterFileName("airbomb");
	size_t module = 1;
	while (module <= 3) {
		m_bombs.push_back(std::make_shared<sf::Texture>());
		m_bombs[module - size_t(1)]->loadFromFile(fighterFileName + std::to_string(module) + ".png");
		module++;
	}
}

void Textures::loadExplosionTextures() {
	std::string explosionFileName("skeleton-explosion");
	int level = 1;
	while (level <= 2) {
		std::vector <std::shared_ptr <sf::Texture>> Explosion;
		int frame = 0;
		std::string temp = explosionFileName + std::to_string(level) + "-animation_";
		while (true) {
			Explosion.push_back(std::make_shared<sf::Texture>());
			if (!Explosion[frame]->loadFromFile(temp + std::to_string(frame) + ".png")) {
				Explosion.pop_back();
				break;		// stop reading more frames when there is no more
			}
			frame++;
		}
		m_explotionAnimation.push_back(Explosion);
		level++;
	}
}

std::string Textures::fighterFileName(FighterType fighter) const {
	std::string fighterFileName = "skeleton";

	if (fighter == FighterType::Tank1)
		fighterFileName += "8-";
	else if (fighter == FighterType::Tank2)
		fighterFileName += "10-";
	else if (fighter == FighterType::Shooter1)
		fighterFileName += "1-";
	else if (fighter == FighterType::Shooter2)
		fighterFileName += "6-";
	else if (fighter == FighterType::Shooter3)
		fighterFileName += "11-";
	else if (fighter == FighterType::Tank3)
		fighterFileName += "12-";

	return fighterFileName;
}

std::string Textures::animationName(AnimationType anim) const {

	if (anim == AnimationType::Idle)
		return "Idle_";
	else if (anim == AnimationType::Walk)
		return "Walk_";
	else if (anim == AnimationType::Die)
		return "Die_";
	else if (anim == AnimationType::Attack)
		return "Attack_";
	return "";
}

std::shared_ptr<sf::Texture> Textures::getBullet() const {
	return m_bullet;
}