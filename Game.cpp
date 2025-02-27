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

		if (playerMove == "C") {return;}
	}

	std::cout << "Your new position is: " << playerPos.x << " " << playerPos.y << "\n";

	for (size_t i = 0; i < player->inventory.size(); ++i) {
		if (player->inventory[i].id != rooms[playerPos.x][playerPos.y].item->id) {
			player->inventory.push_back(*rooms[playerPos.x][playerPos.y].item);
		}
	}

	rooms[playerPos.x][playerPos.y].Description();
}

void Game::useTurn() {
	while (true) {
		std::cout << "\n" << "Choose an item to use (type the item): sword, health potion, or lantern. type C to cancel\n";
		std::string playerDecision;
		std::cin >> playerDecision;

		bool itemExists = false;

		if (playerDecision == "C" || playerDecision == "c") { return; }

		for (size_t i = 0; i < player->inventory.size(); ++i) {
			if (playerDecision == player->inventory[i].name) {
				player->inventory[i].use();
				if (player->inventory[i].uses == 0) {
					player->inventory.erase(player->inventory.begin() + i);
				}
				itemExists = true;
				break;
			}
		}

		if (!itemExists) {
			std::cout << "You don't have that item!\n";
			return;
		}
	}
}


