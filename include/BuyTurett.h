#pragma once

#include "BuyWorldObject.h"

class BuyTurett : public BuyWorldObject {
public:
	BuyTurett(sf::Vector2f);
	void setType(int);

private:
	void draw_object() const;
	TurettType m_turettType = TurettType::Turett1;
};
