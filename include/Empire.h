#pragma once

#include<memory>
#include <list>
#include "Castle.h"
#include "Fighter.h"
#include "Window.h"

class Empire {
public:
	void addFighter(std::shared_ptr <Fighter>);
	void moveFighters(std::shared_ptr <Castle>, std::shared_ptr <Fighter>);
	void draw(float) const;
	//void attackFighters(std::shared_ptr <Castle>, std::shared_ptr <Fighter>);
	void collectDead();

	std::shared_ptr <Castle> getCastle();
	std::shared_ptr <Fighter> getFirstFighter();

private:
	int m_money = 0;
	std::list <std::shared_ptr <Fighter>> m_fighters;
	std::shared_ptr <Castle> m_castle;
};