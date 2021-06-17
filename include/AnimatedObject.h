#pragma once

#include "WorldObject.h"
#include "Animation.h"

class AnimatedObject : public WorldObject {
public:
	AnimatedObject() = default;
	AnimatedObject(const sf::Vector2f&);
	AnimatedObject(const sf::Vector2f&, const bool&);
	AnimatedObject(const sf::Vector2f&, const bool&, const AnimationType&);

	void setAnimationType(const AnimationType&);
	AnimationType getAnimationType() const;
	std::shared_ptr <Animation> getAnimationObject() const;
	void reSetAnimationObject(const FighterType&);

	//---build-body-----------
	virtual void draw(float) const = 0;
	virtual sf::Sprite create(float) const = 0;
private:
	AnimationType m_animationType;
	std::shared_ptr <Animation> m_animation;
};