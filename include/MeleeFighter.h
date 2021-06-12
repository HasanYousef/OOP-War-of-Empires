#pragma once
#include "Fighter.h"

class MeleeFighter : public Fighter {
public:
	MeleeFighter() = default;
	MeleeFighter(const sf::Vector2f&,
		const int&, const int&, const float&, const float&);

	virtual bool fullyDead();

	virtual void attack(const std::shared_ptr<Fighter>& firstEnemy,
		const std::shared_ptr<Castle>& Castle);
	//virtual void move(const std::shared_ptr<Fighter>& nextAlly,
		//const std::shared_ptr<Fighter>& firstEnemy,
		//const std::shared_ptr<Castle>& Castle);
	virtual void draw(float) const;
	virtual sf::Sprite create(float) const;
private:
	std::shared_ptr <Animation> m_animation;
};