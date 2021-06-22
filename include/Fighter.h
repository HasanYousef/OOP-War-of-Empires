#pragma once
#include "AnimatedObject.h"
#include "LiveObject.h"
#include "Castle.h"
#include "FighterAnimation.h"

class Fighter : public AnimatedObject, public LiveObject {
public:
	Fighter() = default;
	Fighter(const sf::Vector2f&,
		const bool&, const int&, const int&, const int&);

	const int& getDefaultAttack() const;
	void setFullyDead() const;
	virtual std::shared_ptr<bool> fullyDead() const;
	int getGoldWorth() const;
	std::shared_ptr <FighterAnimation> getAnimationObject() const;
	void reSetAnimationObject(const FighterType&);
	void setAnimationType(const AnimationType&);
	AnimationType getAnimationType() const;

	virtual void attack(const std::shared_ptr<Fighter>& firstEnemy,
		const std::shared_ptr<Castle>& Castle) = 0;
	virtual void move(const std::shared_ptr<Fighter>& nextAlly,
		const std::shared_ptr<Fighter>& firstEnemy,
		const std::shared_ptr<Castle>& Castle);
	virtual void draw(float) const = 0;
	virtual sf::Sprite create(float) const = 0;

	virtual void addLevel() = 0;

private:
	int m_defaultGoldWorth;
	int m_defaultAttack;
	float m_lastMovement;
	//float m_movementSpeed; //  = milliseconds per one_pixel
	//float m_attackSpeed;   //  = milliseconds per one_attack
	sf::Clock m_clock;
	std::shared_ptr<bool> m_fullyDead;

protected:
	std::shared_ptr <FighterAnimation> m_animation;
	AnimationType m_animationType;
};