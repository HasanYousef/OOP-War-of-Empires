#include "Game.h"

void Game::run() {
	while (true) {
		Menu menu;
		menu.run();

		Match match;
		bool won = match.run();

		EndMenu endMenu;
		endMenu.run(won);
	}
}