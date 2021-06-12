#pragma once

#include <vector>
#include "BuyWorldObject.h"

class InGameUI {
public:
	InGameUI();
	void draw() const;
private:
	std::vector<BuyWorldObject> m_shop;
};
