#pragma once
#include "Animation.h"

class KiteBalloonAnimation : public Animation {
public:
	virtual std::shared_ptr <sf::Texture> get_texture() const;
	bool update(float);
	void set_anim();
private:
	bool m_riseMode = true;
};