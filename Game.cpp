#include "Game.h"

#include "Util.h"

using namespace std;

Game::Game() {
	this->player = new Player;

	for (int i = 0; i < roomRows; ++i) {
		for (int j = 0; j < roomColumn; ++j) {
			int randomDescNum = randomInt(0, 9);
			int roomHaveItem = randomInt(0, 2);
			int randomItemNum = randomInt(0, 2);

			rooms[i][j].setDescription(descriptions[randomDescNum]);

			if (roomHaveItem == 1) {
				rooms[i][j].item = items[randomItemNum];
			} else {
				rooms[i][j].item = nullptr;
			}
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
		std::cout << "\n" << "Choose an action to do. type 1 to Move, type 2 to Use an Item, type 3 to see your inventory.\n";
		std::string playerDecision;
		std::cin >> playerDecision;
		std::cout << "\n";

		if (playerDecision == "1") {
			moveTurn();
		}

		if (playerDecision == "2") {
			useTurn();
		}

		if (playerDecision == "3") {
			if (player->inventory.empty()) {
				std::cout << "You have nothing.\n";
			} else {
				for (size_t i = 0; i < player->inventory.size(); ++i) {
					std::cout << player->inventory[i]->name << "\n";
				}
			}
		}

		if (playerDecision == "4") {
			drawMap();
		}
	}


	delete player;
}

void Game::moveTurn() {
	while (true) {
		std::cout << "Type N, E, S, W to move in that direction. or C to cancel\n";
		std::string playerMove;
		std::cin >> playerMove;
		std::cout << "\n";

		if (playerMove == "N" && playerPos.y < 10) {
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

	if (player->inventory.empty()) {
		player->inventory.push_back(rooms[playerPos.x][playerPos.y].item);
	} 

	for (size_t i = 0; i < player->inventory.size(); ++i) {
		if (player->inventory[i] != nullptr && player->inventory[i]->id != rooms[playerPos.x][playerPos.y].item->id) {
			player->inventory.push_back(rooms[playerPos.x][playerPos.y].item);
		}
	}

	rooms[playerPos.x][playerPos.y].Description();
}

void Game::useTurn() {
	while (true) {
		std::cout << "\n" << "Choose an item to use (type the item): sword, health potion, or lantern. type C to cancel\n";
		std::string playerDecision;
		std::cin >> playerDecision;

		if (playerDecision == "C" || playerDecision == "c") { return; }

		for (size_t i = 0; i < player->inventory.size(); ++i) {
			if (playerDecision == player->inventory[i]->name) {
				player->inventory[i]->use();
				if (player->inventory[i]->uses == 0) {
					player->inventory.erase(player->inventory.begin() + i);
				}
				return;
			}
		}

		std::cout << "You don't have that item!\n";
	}
}

void Game::drawMap() {
	for (int i = 0; i < roomRows; ++i) {
		for (int j = 0; j < roomColumn; ++j) {
			std::string out = (rooms[i][j].item == nullptr) ? "[ ]" : "[+]";
			if (i == playerPos.x && j == playerPos.y) {
				out = "[X]";
			}

			std::cout << out;
		}
		std::cout << "\n";
	}
}


