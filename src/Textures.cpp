#pragma once 

#include "Textures.h"

Textures& Textures::instance() {
	static Textures inst;
	return inst;
}

std::shared_ptr<sf::Texture> Textures::get_ui_texture(UITexture type) const {
	return m_uiTextures[int(type)];
}

std::shared_ptr<sf::Texture> Textures::get_world_obj_texture(WorldObjectType type) const {
	return m_worldObjectTextures[int(type)];
}

std::shared_ptr<sf::Texture> Textures::get_animation_texture(FighterType fighter,
	AnimationType animType, int frame) const {
	return m_animations[int(fighter)][int(animType)][frame];
}

std::shared_ptr<sf::Texture> Textures::get_turett_texture(TurettType turett, int frame) const {
	return m_turetts[int(turett)][frame];
}

int Textures::num_of_anim_frames(FighterType fighter, AnimationType animType) const {
	return m_animations[int(fighter)][int(animType)].size();
}

int Textures::num_of_gun_fire_frames() const {
	return int(m_gunFireAnimations.size());
}

std::shared_ptr<sf::Font> Textures::get_font() const {
	return m_font;
}

std::shared_ptr<sf::Texture> Textures::get_gun_fire_texture(int frame) const {
	return m_gunFireAnimations[frame];
}

Textures::Textures() {
	load_ui_textures();
	load_world_obj_textures();
	load_anim_textures();
	load_turetts_texturs();
	load_font();
	load_gun_fire_textures();
}

void Textures::load_ui_textures() {
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
}

void Textures::load_world_obj_textures() {
	for (int i = 0; i <= NUM_OF_WORLD_OBJECT_TYPES; i++) {
		std::shared_ptr ptr = std::make_shared<sf::Texture>();
		m_worldObjectTextures.push_back(ptr);
	}

	m_worldObjectTextures[int(WorldObjectType::MatchBackground)]->loadFromFile("match-background.png");
	m_worldObjectTextures[int(WorldObjectType::Floor)]->loadFromFile("floor-texture.png");
	m_worldObjectTextures[int(WorldObjectType::Castle)]->loadFromFile("castle-texture.png");
}

void Textures::load_anim_textures() {
	for (int i = 0; i < NUM_OF_FIGHTER_TYPES; i++) {
		std::vector <std::vector <std::shared_ptr <sf::Texture>>> fighter;
		FighterType fighterType = FighterType(i);

		for (int j = 0; j < NUM_OF_ANIMATION_TYPES; j++) {
			std::string fighterFileName = fighter_file_name(fighterType);
			AnimationType animationType = AnimationType(j);
			// just the Tank1 and the Tank2 fighters have Attack animations
			if(animationType == AnimationType::Attack)
				if (fighterType != FighterType::Tank1 && fighterType != FighterType::Tank2)
					break;

			std::vector <std::shared_ptr <sf::Texture>> anim;
			fighterFileName += animation_name(animationType);
			int frame = 0;
			while (true) {
				anim.push_back(std::make_shared<sf::Texture>());
				if (!anim[frame]->loadFromFile(fighterFileName + std::to_string(frame) + ".png")) {
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

void Textures::load_turetts_texturs() {
	std::string turettFileName = "skeleton";
	"skeleton1-Shoot_0";
	for (int i = 0; i < NUM_OF_TURETT_TYPES; i++) {
		std::vector <std::shared_ptr <sf::Texture>> turett;
		TurettType fighterType = TurettType(i);

		std::vector <std::shared_ptr <sf::Texture>> anim;
		turettFileName += (std::to_string(i) + "-Shoot_");
		int frame = 0;
		while (true) {
			anim.push_back(std::make_shared<sf::Texture>());
			if (!anim[frame]->loadFromFile(turettFileName + std::to_string(frame) + ".png")) {
				anim.pop_back();
				break;		// stop reading more frames when there is no more
			}
			frame++;
		}

		m_turetts.push_back(turett);
	}
}

void Textures::load_font() {
	m_font = std::make_shared<sf::Font>();
	m_font->loadFromFile("font.ttf");
}

void Textures::load_gun_fire_textures() {
	std::string fighterFileName("skeleton-animation_");
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

std::string Textures::fighter_file_name(FighterType fighter) const {
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

	return fighterFileName;
}

std::string Textures::animation_name(AnimationType anim) const {

	if (anim == AnimationType::Idle)
		return "Idle_";
	else if (anim == AnimationType::Walk)
		return "Walk_";
	else if (anim == AnimationType::Die)
		return "Die_";
	else if (anim == AnimationType::Attack)
		return "Attack_";
}