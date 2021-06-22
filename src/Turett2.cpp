#pragma once

#include "Turett2.h"

Turett2::Turett2(const sf::Vector2f& pos, bool team)
	: Turett(pos, team) {
	m_animation = std::make_unique<TurettAnimation>(TurettType::Turett2);
}

TurettType Turett2::getType() const {
	return TurettType::Turett2;
}

int Turett2::getDamage() const {
	return 50;
}