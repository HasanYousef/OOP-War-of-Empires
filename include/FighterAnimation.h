#pragma once

#include "Animation.h"

class FighterAnimation : public Animation {
public:
	FighterAnimation(FighterType fighter) : m_fighterType(fighter) {}
	void setAnimType(AnimationType);
	std::shared_ptr <sf::Texture> getTexture() const;
	AnimationType update(float);
	FighterType& getFighterType();

private:
	FighterType m_fighterType;
	AnimationType m_currAnim = AnimationType::Idle;
};
