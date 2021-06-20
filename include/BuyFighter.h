#pragma once

#include "BuyWorldObject.h"

class BuyFighter : public BuyWorldObject {
public:
	BuyFighter(FighterType, sf::Vector2f, int);

private:
	void draw_object() const;

	FighterType m_fighterType;
};
