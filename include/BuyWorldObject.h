#pragma once

#include <SFML/Graphics.hpp>

class BuyWorldObject {
public:
	void draw() const;
private:
	sf::Vector2f m_position;
}