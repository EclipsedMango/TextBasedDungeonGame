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

	bool thingy = false;

	if (reply == "play") {
		thingy = true;
	}

	std::cout << "\n" << "These are your base stats: \nLevel: "
		<< player->level
		<< "\nHP: " << player->healthPoints
		<< "\nDamage: " << player->baseDamage << "\n";

	while (thingy) {
		std::cout << "\n"
			<< "Choose an action to do. type (1, 2, 3, 4, 5, or 6).\n"
			<< "1: Move,\n"
			<< "2: Use Item.\n"
			<< "3: Open Inventory.\n"
			<< "4: Open Map.\n"
			<< "5: Check spells.\n"
			<< "6: Leave dungeon.\n";

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
				std::cout << "You have no items, explore to find some!\n";
			}

			for (int i = 0; i < player->inventory.size(); ++i) {
				if (player->inventory[i] != nullptr) {
					std::cout << player->inventory[i]->name << "\n";
				}
			}
		}

		if (playerDecision == "4") {
			drawMap();
		}

		if (playerDecision == "5") {
			std::cout << "Type a spell to see if you have it.\n";
			std::string playerReply;
			std::cin >> playerReply;

			if (player->findSpell(playerReply)) {
				std::cout << "You do have " << playerReply << ".\n";
			} else {
				std::cout << "You do not have " << playerReply << ".\n";
			}
		}

		if (playerDecision == "6") {
			leaveDungeon();
			return;
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
			playerPos.y -= 1;
			break;
		}

		if (playerMove == "E") {
			playerPos.x += 1;
			break;
		}

		if (playerMove == "S") {
			playerPos.y += 1;
			break;
		}

		if (playerMove == "W") {
			playerPos.x -= 1;
			break;
		}

		if (playerMove == "C") {return;}
	}

	std::cout << "Your new position is: " << playerPos.x << " " << playerPos.y << "\n";

	if (player->inventory.empty() && rooms[playerPos.x][playerPos.y].item != nullptr) {
		player->inventory.push_back(rooms[playerPos.x][playerPos.y].item);
	}

	for (size_t i = 0; i < player->inventory.size(); ++i) {
		if (rooms[playerPos.x][playerPos.y].item != nullptr && player->inventory[i]->id != rooms[playerPos.x][playerPos.y].item->id) {
			player->inventory.push_back(rooms[playerPos.x][playerPos.y].item);
		}
	}

	rooms[playerPos.x][playerPos.y].Description();
}

void Game::useTurn() {
	while (true) {
		std::cout << "Choose an item to use (type the item): sword, health potion, or lantern. type C to cancel\n";
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
	for (int i = 0; i < roomColumn; ++i) {
		for (int j = 0; j < roomRows; ++j) {
			std::string out = (rooms[j][i].item == nullptr) ? "[ ]" : "[+]";
			if (j == playerPos.x && i == playerPos.y) {
				out = "[X]";
			}

			std::cout << out;
		}
		std::cout << "\n";
	}
}

void Game::leaveDungeon() {
	std::cout << "You left the dungeon.\n" << "\n";

	std::cout << "Statistics:\n"
		<< "Player level: " << player->level << "\n"
		<< "Player HP: " << player->healthPoints << "\n"
		<< "Player Damage: " << player->baseDamage << "\n"
		<< "Loot you left with:\n" << "\n";

	if (!player->inventory.empty()) {
		for (int i = 0; i < player->inventory.size(); ++i) {
			std::cout << player->inventory[i]->name << "\n";
		}

	} else {
		std::cout << "Nothing.\n";
	}

	std::cout << "\nGold you earned: " << player->gold << "\n";
	std::cout << "GG, I hope you had fun!\n";
}

