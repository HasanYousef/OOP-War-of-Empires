#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Textures.h"

class Match {
public:
	void run();

private:
	void draw_world();
	void draw_background(std::shared_ptr<sf::RenderWindow>);
};
