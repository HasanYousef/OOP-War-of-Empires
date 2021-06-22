#pragma once 

#include "Levels.h"

Levels& Levels::instance() {
	static Levels inst;
	return inst;
}

int Levels::get_level(const bool& team, const int& objectType) const {
	return m_levels[team ? 0:1][objectType];
}

void Levels::add_level(const bool& team, const int& objectType){
	(m_levels[team ? 0 : 1][objectType])++;
}

Levels::Levels() {
	for (int i = 0; i < 2; i++) {
		std::vector<int> currTeam(NUM_OF_FIGHTER_TYPES);
		for (int j = 0; j < NUM_OF_FIGHTER_TYPES; j++)
			currTeam[j] = 1;
		m_levels.push_back(currTeam);
	}	
	for (int i = 0; i < 2; i++) {
		m_kiteLevels.push_back(1);
	}
}

int Levels::get_kite_level(const bool& team) const {
	return m_kiteLevels[team ? 0 : 1];
}
void Levels::add_kite_level(const bool& team) {
	(m_kiteLevels[team ? 0 : 1])++;
}