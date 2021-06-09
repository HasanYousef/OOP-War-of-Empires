#pragma once

#include<memory>
#include <list>
#include "Castle.h"
#include "Fighter.h"
#include "Window.h"

class Empire {
public:
	void draw() const;
	void addFighter(Fighter&);
	void moveFighters(Castle&, Fighter&);
	void draw(std::shared_ptr<sf::RenderWindow>);
	void attackFighters(Castle&, Fighter&);
	void collectDead();
	//---get-functions----------
	Castle getCastle();
	Fighter getFirstFighter();

private:
	int m_money = 0;
	std::list <std::shared_ptr <Fighter>> m_fighters;
	std::shared_ptr <Castle> m_castle;
};