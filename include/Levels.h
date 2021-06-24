#pragma once
#include "macros.h"
#include <vector>

class Levels {
public:
	friend class MeleeFighter1;
	friend class MeleeFighter2;
	friend class RangeFighter;
	friend class RangeFighter1;
	friend class RangeFighter2;
	friend class RangeFighter3;
	friend class RangeFighter4;
	friend class KiteBalloon;
	static Levels& instance();
private:
	int getLevel(const bool& team, const int& objctType) const;
	void addLevel(const bool& team, const int& objctType);
	int getKiteLevel(const bool& team) const;
	void addKiteLevel(const bool& team);
	Levels();
	std::vector<std::vector<int>> m_levels;
	std::vector<int> m_kiteLevels;
};