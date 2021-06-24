#pragma once

#include "Animation.h"

class FighterAnimation : public Animation {
public:
	FighterAnimation(FighterType fighter) : m_fighterType(fighter) {}
	void set_anim_type(AnimationType);
	std::shared_ptr <sf::Texture> get_texture() const;
	AnimationType update(float);
	FighterType& getFighterType();

private:
	FighterType m_fighterType;
	AnimationType m_currAnim = AnimationType::Idle;
};
