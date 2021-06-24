#pragma once
#include "Animation.h"

class AirBombAnimation : public Animation {
public:
	std::shared_ptr <sf::Texture> getTexture() const;
	bool update(float);
	void setAnim();
	void setAnimModule(int);
private:
	int m_airBombModule = 1;
	bool m_explosive = false;
};