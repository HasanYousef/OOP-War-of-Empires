#pragma once

#include<memory>
#include <list>
#include "Castle.h"
#include "Fighter.h"
#include "Window.h"
#include "MeleeFighter.h"

class Empire {
public:
	Empire(bool);
	void addFighter(std::shared_ptr <Fighter>);
	void moveFighters(std::shared_ptr <Castle>, std::shared_ptr <Fighter>);
	void draw(float) const;
	//void attackFighters(std::shared_ptr <Castle>, std::shared_ptr <Fighter>);
	void collectDead();

	std::shared_ptr <Castle> getCastle();
	std::shared_ptr <Fighter> getFirstFighter();

private:
	bool m_team;
	int m_money = 450;
	std::list <std::shared_ptr <Fighter>> m_fighters;
	std::shared_ptr <Castle> m_castle;
};