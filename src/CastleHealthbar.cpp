#pragma once

#include "CastleHealthbar.h"

CastleHealthbar::CastleHealthbar(bool team, int maxHealth) 
	: m_background(team), m_filled(team, maxHealth) {}

void CastleHealthbar::draw() const {
	m_background.draw();
	m_filled.draw();
}

void CastleHealthbar::update(int hp) {
	m_filled.update(hp);
}