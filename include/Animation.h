#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"
#include "Textures.h"

class Animation {
public:
	Animation(AnimationType gunFire) : m_currAnim(gunFire), m_fighterType(FighterType::Shooter1) {}
	Animation(FighterType fighter) : m_fighterType(fighter) {}
	Animation(TurettType turett) : m_turettType(turett) {}
	void set_anim_type(AnimationType);
	std::shared_ptr <sf::Texture> get_texture() const;
	AnimationType update(float);
	int getCurrFrame();

private:
	FighterType m_fighterType;
	TurettType m_turettType;
	AnimationType m_currAnim = AnimationType::Idle;
	float m_totalTime = 0;
	int m_currFrame = 0;
};
