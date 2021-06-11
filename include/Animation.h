#pragma once

#include <SFML/Graphics.hpp>

#include "macros.h"
#include "Textures.h"

class Animation {
public:
	Animation(FighterType fighter) : m_fighterType(fighter) {};
	void set_anim_type(AnimationType);
	std::shared_ptr <sf::Texture> get_texture() const;
	AnimationType update(float);
	int getCurrFrame();

private:
	FighterType m_fighterType;
	AnimationType m_currAnim = AnimationType::Idle;
	float m_totalTime = 0;
	int m_currFrame = 0;
};
