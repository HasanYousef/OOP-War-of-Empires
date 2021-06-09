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

	virtual void attack(Fighter*, Castle* ) = 0;
	virtual void move(Fighter* nextAlly, Fighter* firstEnemy, Castle*) = 0;
	virtual void draw(sf::RenderWindow&) const = 0;
	virtual sf::Sprite create() const = 0;

private:
	float m_level;
	float m_defaultGoldWorth;
	float m_defaultAttack;
	//float m_movementSpeed; //  = milliseconds per one_pixel
	//float m_attackSpeed;   //  = milliseconds per one_attack
};