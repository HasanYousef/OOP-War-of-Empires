#pragma once

#include "BuyWorldObject.h"

class BuyFighter : public BuyWorldObject {
public:
	BuyFighter(FighterType, sf::Vector2f, int);
	void setType(int) {};

private:
	void drawObject() const;

	FighterType m_fighterType;
};
