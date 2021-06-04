#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Sounds.h"
#include "Textures.h"

class Match {
public:
	void run();

private:
	void draw_world(std::shared_ptr<sf::RenderWindow>);
};
