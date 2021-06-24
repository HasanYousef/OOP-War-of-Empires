#pragma once
#include "Animation.h"

class KiteBalloonAnimation : public Animation {
public:
	virtual std::shared_ptr <sf::Texture> getTexture() const;
	bool update(float);
	void setAnim();
	void setKiteLevel(int);
private:
	int m_kiteLevel = 1;
	bool m_riseMode = true;
};