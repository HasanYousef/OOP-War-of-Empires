#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Sounds.h"
#include "Textures.h"
#include "MenuBackground.h"

class EndMenu {
public:
	void run(bool);

private:
	void draw(std::shared_ptr<sf::RenderWindow>, bool);

	MenuBackground m_background;
};
