#pragma once

#include<memory>
#include <list>
#include "Castle.h"
#include "Fighter.h"
#include "Window.h"
#include "MeleeFighter1.h"
#include "MeleeFighter2.h"
#include "RangeFighter1.h"
#include "RangeFighter2.h"
#include "RangeFighter3.h"
#include "RangeFighter4.h"
#include "KiteBalloon.h"
#include "Turett.h"	//@#$%@#$%#$^$#$$

class Empire {
public:
	Empire(bool);
	void addFighter(std::shared_ptr <Fighter>);
	void moveFighters(std::shared_ptr <Castle>, std::shared_ptr <Fighter>);
	void draw(float) const;
	void attackFighters(std::shared_ptr <Castle>, std::shared_ptr <Fighter>);
	void collectDead();
	void pay(int);
	void addKiteBalloon();
	void moveKiteBalloon();
	void moveAirUnites();
	void colliedAirUnites(std::list <std::shared_ptr <Fighter>>& enemies, const sf::Vector2f&);
	void getLayedBomb();
	void getSentBullet();

	std::shared_ptr <Castle> getCastle();
	std::shared_ptr <Fighter> getFirstFighter();
	std::list<std::shared_ptr<Fighter>>& getFighters();

	//---Get-Functions----------
	bool ifGetOccupied() const;
	int getMoney() const;

private:
	bool m_team;
	int m_money = 30000;
	std::list <std::shared_ptr <Fighter>> m_fighters;
	std::shared_ptr <Castle> m_castle;
	std::shared_ptr <KiteBalloon> m_kiteBalloon;
	Turett m_turett;
	std::list<std::shared_ptr <AirUnites>> m_airUnites;
};