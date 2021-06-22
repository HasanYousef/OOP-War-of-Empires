#pragma once
#include "RangeFighter.h"

class RangeFighter4 : public RangeFighter {
public:
	RangeFighter4() = default;
	RangeFighter4(const sf::Vector2f&, const int&);

	virtual void move(const std::shared_ptr<Fighter>& nextAlly,
		const std::shared_ptr<Fighter>& firstEnemy,
		const std::shared_ptr<Castle>& Castle);

	virtual sf::Sprite create(float) const;

	void addLevel();
};