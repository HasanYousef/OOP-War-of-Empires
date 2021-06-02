#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Textures.h"
#include "Button.h"

class Menu {
public:
	void run();

private:
	void draw(std::shared_ptr<sf::RenderWindow>);
	void draw_background(std::shared_ptr<sf::RenderWindow>);

	std::vector<Button> m_buttons;
};
