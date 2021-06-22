#pragma once

#include "Turett3.h"

Turett3::Turett3(const sf::Vector2f& pos, bool team)
	: Turett(pos, team) {
	m_animation = std::make_unique<TurettAnimation>(TurettType::Turett3);
}

TurettType Turett3::getType() const {
	return TurettType::Turett3;
}

int Turett3::getDamage() const {
	return 70;
}