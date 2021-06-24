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
#include "Turett1.h"
#include "Turett2.h"
#include "Turett3.h"

class Empire {
public:
	Empire(bool);
	void addFighter(std::shared_ptr <Fighter>);
	void moveFighters(std::shared_ptr <Castle>, std::shared_ptr <Fighter>);
	void draw(float) const;
	void attackFighters(std::shared_ptr <Castle>, std::shared_ptr <Fighter>);
	void collectEnemyMoney(const std::list<std::shared_ptr<Fighter>>&);
	void collectDead();
	void pay(int);
	void addKiteBalloon();
	void moveKiteBalloon();
	void moveAirUnites();
	void colliedAirUnites(std::list <std::shared_ptr <Fighter>>& enemies, const sf::Vector2f&);
	void getLayedBomb();
	void getSentBullet();
	void giveMoney(int);
	int buyTurett(int);

	std::shared_ptr <Castle> getCastle();
	std::shared_ptr <Fighter> getFirstFighter();
	std::list<std::shared_ptr<Fighter>>& getFighters();

	//---Get-Functions----------
	bool ifGetOccupied() const;
	int getMoney() const;
	int getFightersNum() const;

private:
	bool m_team;
	int m_money = INIT_MONEY;
	std::list <std::shared_ptr <Fighter>> m_fighters;
	std::shared_ptr <Castle> m_castle;
	std::shared_ptr <KiteBalloon> m_kiteBalloon;
	std::list<std::shared_ptr <AirUnites>> m_airUnites;
	std::unique_ptr<Turett> m_turetts[NUM_OF_TURETTS_STANDS];
};