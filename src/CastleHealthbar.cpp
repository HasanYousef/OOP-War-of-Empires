#pragma once

#include "CastleHealthbar.h"

CastleHealthbar::CastleHealthbar(bool team, int maxHealth) 
	: m_team(team), m_maxHealth(maxHealth),
	m_background(team) {}

void CastleHealthbar::draw() const {
	m_background.draw();
}