#pragma once
#include "RangeFighter.h"

class RangeFighter3 : public RangeFighter {
public:
	RangeFighter3() = default;
	RangeFighter3(const sf::Vector2f&, const int&);
	
	virtual void move(const std::shared_ptr<Fighter>& nextAlly,
		const std::shared_ptr<Fighter>& firstEnemy,
		const std::shared_ptr<Castle>& Castle);
	void addLevel();
};