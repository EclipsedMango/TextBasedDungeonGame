#include "Game.h"

#include "Util.h"

using namespace std;

Game::Game() {
	this->player = new Player;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			int randomDescNum = randomInt(0, 9);
			int randomItemNum = randomInt(0, 2);

			rooms[i][j].setDescription(descriptions[randomDescNum]);
			rooms[i][j].item = items[randomItemNum];
		}
	}
}

Game::~Game() {
	delete player;
	delete[] rooms;
}

void Game::run() {
	player->sortSpells();

	std::cout << "Type 'play' to play DungeonGameTheGame.\n";
	std::string reply;
	std::cin >> reply;

	if (reply != "play") {
		std::cout << "You didn't type 'play'. Goodbye!\n";
		delete player;
		return;
	}

	std::cout << "\n" << "These are your base stats: \nLevel: "
		<< player->level
		<< "\nHP: " << player->healthPoints
		<< "\nDamage: " << player->baseDamage << "\n";

	std::cout << "\n";

	while (reply == "play") {
		std::cout << "Type N, E, S, W to move in a direction.\n";
		std::string moveReply;
		std::cin >> moveReply;
	}


	delete player;
}