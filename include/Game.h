#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

// #include "Menu.h"
#include "Match.h"
#include "Window.h"

class Game {
public:
	Game();
	void run();

private:
	void run_menu();
	void run_match();
	void draw_world();
};
