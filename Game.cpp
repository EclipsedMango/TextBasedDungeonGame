#include "Game.h"

using namespace std;

int main() {
	Game *newGame = new Game;
	newGame->run();
	return 0;
}

void Game::run() {
	Player *player = new Player;
	player->sortSpells();
}