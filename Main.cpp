#include "Game.h"

int main() {
	Game* newGame = new Game;
	newGame->Run();

	// Delay the closing and deletion of game and window.
	int input;
	std::cin >> input;

	delete newGame;
	return 0;
}