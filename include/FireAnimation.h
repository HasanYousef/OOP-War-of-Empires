#pragma once

#include "Animation.h"

class FireAnimation : public Animation {
public:
	std::shared_ptr <sf::Texture> getTexture() const;
	void setAnim();
};
