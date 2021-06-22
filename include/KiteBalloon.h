#pragma once
#include "AnimatedObject.h"
#include "KiteBalloonAnimation.h"
#include "AirBomb.h"

class KiteBalloon : public AnimatedObject {
public:
	KiteBalloon() = default;
	KiteBalloon(const sf::Vector2f&, const bool&);

	void move();
	std::shared_ptr<AirUnites> dropBomb();
	void addLevel();

	virtual void draw(float) const ;
	virtual sf::Sprite create(float) const ;

private:
	std::shared_ptr<KiteBalloonAnimation> m_animation;
	std::shared_ptr < sf::Clock> m_movementClock;
	std::shared_ptr < sf::Clock> m_sendBombClock;
};