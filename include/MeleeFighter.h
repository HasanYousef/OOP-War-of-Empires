#pragma once
#include "Fighter.h"

class MeleeFighter : public Fighter {
public:
	MeleeFighter() = default ;
	MeleeFighter(const sf::Vector2f&,
		const int&, const int&, const float&, const float&);
private:
	std::shared_ptr <Animation> m_animation;
};