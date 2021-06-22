#pragma once
#include "macros.h"
#include <vector>

class Levels {
public:
	friend class MeleeFighter1;
	friend class MeleeFighter2;
	friend class RangeFighter1;
	friend class RangeFighter2;
	friend class RangeFighter3;
	friend class RangeFighter4;
	friend class KiteBalloon;
	static Levels& instance();
private:
	int get_level(const bool& team, const int& objctType) const;
	void add_level(const bool& team, const int& objctType);
	int get_kite_level(const bool& team) const;
	void add_kite_level(const bool& team);
	Levels();
	std::vector<std::vector<int>> m_levels;
	std::vector<int> m_kiteLevels;
};