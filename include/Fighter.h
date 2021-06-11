#pragma once
#include "AnimatedObject.h"
#include "LiveObject.h"
#include "Castle.h"
#include "Animation.h"

class Fighter : public AnimatedObject, public LiveObject {
public:
	Fighter() = default ;
	Fighter(const sf::Vector2f&,
		const bool&, const int&, const float&, const float&);

	void addLevel();
	const float& getLevel() const;
	const float& getDefaultAttack() const;
	virtual bool fullyDead() = 0;
	float getGoldWorth() const;

	virtual void attack(const std::shared_ptr<Fighter>& firstEnemy,
		const std::shared_ptr<Castle>& Castle) = 0;
	virtual void move(const std::shared_ptr<Fighter>& nextAlly,
		const std::shared_ptr<Fighter>& firstEnemy,
		const std::shared_ptr<Castle>& Castle);
	virtual void draw(float) const = 0;
	virtual sf::Sprite create(float) const = 0;

private:
	float m_level;
	float m_defaultGoldWorth;
	float m_defaultAttack;
	float m_lastMovement;
	//float m_movementSpeed; //  = milliseconds per one_pixel
	//float m_attackSpeed;   //  = milliseconds per one_attack
	sf::Clock m_clock;
};