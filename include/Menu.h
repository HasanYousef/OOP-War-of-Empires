#pragma once

#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Textures.h"
#include "MenuBackground.h"
#include "GameTitle.h"
#include "StartButton.h"
#include "ExitGameButton.h"

class Menu {
public:
	void run();

private:
	void draw(std::shared_ptr<sf::RenderWindow>);

	MenuBackground m_background;
	GameTitle m_title;
	StartButton m_startButton;
	ExitGameButton m_exitGameButton;
};
