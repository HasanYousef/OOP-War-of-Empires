#pragma once

#include "BuyWorldObject.h"
#include "BuyKiteBalloonButton.h"

class BuyKiteBalloon : public BuyWorldObject {
public:
	BuyKiteBalloon(sf::Vector2f);
	void setType(int) {};
	void set_can_buy(bool can);
	void draw() const;

private:
	void draw_object() const;
	std::unique_ptr<BuyKiteBalloonButton> m_button;
};