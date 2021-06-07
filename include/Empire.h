#pragma once

#include<forward_list>
#include<memory>
#include <list>
#include "Base.h"
#include "LiveAnimatedObject.h"
#include "Window.h"

class Empire {
public:
	void draw() const;
	void addFighter(LiveAnimatedObject&);
	void moveFighters(sf::Vector2f&, &sf::Vector2f);
	void draw(std::shared_ptr<sf::RenderWindow>);
	//---get-functions----------
	sf::Sprite getCastle() const;
	sf::Sprite getFirstFighter() const;

private:
	std::list <std::shared_ptr <LiveAnimatedObject>> m_fighters;
	Base m_castle;
};