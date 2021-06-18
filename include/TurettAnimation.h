#pragma once

#include "Animation.h"

class FireAnimation : public Animation {
public:
	std::shared_ptr <sf::Texture> get_texture() const;
	bool update(float);
	void set_anim();

private:

};
