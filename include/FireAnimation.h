#pragma once

#include "Animation.h"

class FireAnimation : public Animation {
public:
	std::shared_ptr <sf::Texture> get_texture() const;
	void set_anim();
};
