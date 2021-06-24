#pragma once

#include "BuyTurett.h"

BuyTurett::BuyTurett(sf::Vector2f pos)
	: BuyWorldObject(pos, TURETT1_PRICE) {
}

void BuyTurett::setType(int type) {
	int price = 0;
	switch (TurettType(type)) {
	case TurettType::Turett1:
		price = TURETT1_PRICE;
		break;
	case TurettType::Turett2:
		price = TURETT2_PRICE;
		break;
	case TurettType::Turett3:
		price = TURETT3_PRICE;
	}
	m_button->setPrice(price);
	m_turettType = TurettType(type);
}

void BuyTurett::drawObject() const {
	sf::Sprite turett(*Textures::instance().getTurettTexture(m_turettType, 0));
	turett.scale(0.4, 0.4);
	sf::FloatRect Rect = turett.getLocalBounds();
	turett.setOrigin(Rect.left + Rect.width / 2.0f,
		Rect.top + Rect.height / 2.0f);
	turett.setPosition(m_position.x + 55, m_position.y + 50);
	Window::instance().getWindow()->draw(turett);
}