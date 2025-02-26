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

	while (reply == "play") {
		std::cout << "\n" << "Choose an action to do. type 1 to Move, type 2 to Use an Item, type 3 to attack.\n";
		std::string playerDecision;
		std::cin >> playerDecision;
		std::cout << "\n";

		if (playerDecision == "1") {
			moveTurn();
		}

		if (playerDecision == "2") {}

		if (playerDecision == "3") {}
	}


	delete player;
}

void Game::moveTurn() {
	while (true) {
		std::cout << "Type N, E, S, W to move in that direction. or C to cancel\n";
		std::string playerMove;
		std::cin >> playerMove;
		std::cout << "\n";

		if (playerMove == "N") {
			playerPos.y += 1;
			break;
		}

		if (playerMove == "E") {
			playerPos.x += 1;
			break;
		}

		if (playerMove == "S") {
			playerPos.y -= 1;
			break;
		}

		if (playerMove == "W") {
			playerPos.x -= 1;
			break;
		}

		if (playerMove == "C") {break;}
	}

	std::cout << "Your new position is: " << playerPos.x << " " << playerPos.y << "\n";
	rooms[playerPos.x][playerPos.y].Description();
}

void Game::useTurn() {

}

void Game::attackTurn() {

}


