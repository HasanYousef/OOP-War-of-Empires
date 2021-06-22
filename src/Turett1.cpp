#pragma once

#include "Turett1.h"

Turett1::Turett1(const sf::Vector2f& pos, bool team)
	: Turett(pos, team) {
	m_animation = std::make_unique<TurettAnimation>(TurettType::Turett1);
}

TurettType Turett1::getType() const {
	return TurettType::Turett1;
}

int Turett1::getDamage() const {
	return 30;
}