#pragma once
#include "WorldObject.h"

class AnimatedObject : public WorldObject {
public:
	AnimatedObject();
	AnimatedObject(const WorldObjectType&, const sf::Vector2f&);
	AnimatedObject(const WorldObjectType&, const sf::Vector2f&, const int&);

	void draw(sf::RenderWindow&) const;
	void setAnimationType(const AnimationType&);
	AnimationType getCurrentAnimationType() const;
	AnimationType getLastAnimationType() const;

	//---build-body-----------
	virtual sf::Sprite create() const;
private:
	AnimationType m_currentAnimationType, m_lastAnimationType;
};