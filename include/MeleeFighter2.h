#pragma once
#include "MeleeFighter.h"

class MeleeFighter2 : public MeleeFighter {
public:
	MeleeFighter2() = default;
	MeleeFighter2(const sf::Vector2f&, const int&);
	void addLevel();
};