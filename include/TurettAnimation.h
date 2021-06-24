#pragma once

#include "Animation.h"

class TurettAnimation : public Animation {
public:
	TurettAnimation(TurettType type) : m_turettType(type) {}
	std::shared_ptr <sf::Texture> getTexture() const;
	bool update(float);
	void setIsShooting(bool);
	bool isShooting() const;
	void setAnim();

private:
	bool m_isShooting = false;
	TurettType m_turettType;
};
