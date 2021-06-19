#pragma once
#include "Animation.h"

class AirBombAnimation : public Animation {
public:
	std::shared_ptr <sf::Texture> get_texture() const;
	bool update(float);
	void set_anim();
private:
	int m_airBombModule = 1;
	bool m_explosive = false;
};