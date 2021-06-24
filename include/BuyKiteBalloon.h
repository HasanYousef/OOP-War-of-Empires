#pragma once

#include "BuyWorldObject.h"
#include "BuyKiteBalloonButton.h"

class BuyKiteBalloon : public BuyWorldObject {
public:
	BuyKiteBalloon(sf::Vector2f);
	void setType(int) {};
	void setCanBuy(bool can);
	bool handleClick(const sf::Vector2f location);
	void draw() const;

private:
	void drawObject() const;
	std::unique_ptr<BuyKiteBalloonButton> m_button;
};
