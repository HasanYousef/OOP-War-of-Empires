#pragma once
#include "AnimatedObject.h"
#include "FireAnimation.h"
#include "Sounds.h"

class GunFire : public AnimatedObject {
public:
	GunFire() = default;
	GunFire(const sf::Vector2f&, const bool&);
	void activate() const;
	void disActivate() const;

	//---build-body-----------
	virtual void draw(float) const;
	virtual sf::Sprite create(float) const;
private:
	std::shared_ptr<bool> m_activated;
	std::shared_ptr< FireAnimation> m_animation;
};