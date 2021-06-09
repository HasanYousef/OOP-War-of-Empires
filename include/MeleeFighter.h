#pragma once
#include "Fighter.h"

class MeleeFighter : public Fighter {
public:
	MeleeFighter() = default ;
	MeleeFighter(const sf::Vector2f&,
		const int&, const int&, const float&, const float&);

	//virtual void attack(const Fighter*, const Castle*);
	//virtual void move(const Fighter* nextAlly, const Fighter* firstEnemy, const Castle*);
	virtual void draw(sf::RenderWindow&) const;
	virtual sf::Sprite create() const;
private:
	std::shared_ptr <Animation> m_animation;
};