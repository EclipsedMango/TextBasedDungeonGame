#include "Game.h"

int main() {
	Game* newGame = new Game;
	newGame->run();
	delete newGame;
	return 0;
}
