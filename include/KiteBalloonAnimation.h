#pragma once
#include "Animation.h"

class KiteBalloonAnimation : public Animation {
public:
	virtual std::shared_ptr <sf::Texture> get_texture() const;
	bool update(float);
	void set_anim();
	void set_kite_level(int);
private:
	int m_kiteLevel = 1;
	bool m_riseMode = true;
};