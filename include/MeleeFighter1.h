#pragma once
#include "MeleeFighter.h"

class MeleeFighter1 : public MeleeFighter{
public:
	MeleeFighter1() = default;
	MeleeFighter1(const sf::Vector2f&, const int&);
	void addLevel();
};