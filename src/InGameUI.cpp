#pragma once

#include "InGameUI.h"

InGameUI::InGameUI() {
	for (int i = 0; i < NUM_OF_FIGHTER_TYPES; i++) {
		sf::Vector2f pos(16 * (i + 1) + 110 * i, 16);
		m_shop.push_back(BuyWorldObject(FighterType(i), pos, 100 * (i + 1)));
	}
}

void InGameUI::draw() const {
	for (int i = 0; i < m_shop.size(); i++)
		m_shop[i].draw();
}

