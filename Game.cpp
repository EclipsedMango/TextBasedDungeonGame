#include "Game.h"

#include "Enemy.h"
#include "Util.h"

using namespace std;

Game::Game() {
	this->player = new Player;

	for (int i = 0; i < randomInt(8, 16); ++i) {
		enemies.push_back(new Enemy);
	}

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
	for (int i = 0; i < enemies.size(); ++i) {
		delete enemies[i];
	}

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
		if (player->movesRemaining <= 0) {
			std::cout << "\nYou ran of of moves.\n";
			leaveDungeon(false);
			return;
		}

		std::cout << "\n"
			<< "Choose an action to do. type (1, 2, 3, 4, 5, 6, or 7).\n"
			<< "1: Move.\n"
			<< "2: Use Item.\n"
			<< "3: Open Inventory.\n"
			<< "4: Open Map.\n"
			<< "5: Check spells.\n"
			<< "6: Shows Stats.\n"
			<< "7: Leave dungeon.\n";

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
			std::cout << "Statistics:\n"
				<< "Player level: " << player->level << "\n"
				<< "Player HP: " << player->healthPoints << "\n"
				<< "Player Damage: " << player->baseDamage << "\n";
		}

		if (playerDecision == "7") {
			leaveDungeon(false);
			return;
		}
	}
}

void Game::moveTurn() {
	while (true) {
		std::cout << "Type N, E, S, W to move in that direction. or C to cancel\n";
		std::string playerMove;
		std::cin >> playerMove;
		playerMove[0] = std::tolower(static_cast<unsigned char>(playerMove[0]));
		std::cout << "\n";

		if (playerMove == "n" && playerPos.y < 10) {
			player->movesRemaining -= 1;
			playerPos.y -= 1;
			break;
		}

		if (playerMove == "e" && playerPos.x < 10) {
			player->movesRemaining -= 1;
			playerPos.x += 1;
			break;
		}

		if (playerMove == "s" && playerPos.y > 0) {
			player->movesRemaining -= 1;
			playerPos.y += 1;
			break;
		}

		if (playerMove == "w" && playerPos.x > 0) {
			player->movesRemaining -= 1;
			playerPos.x -= 1;
			break;
		}

		if (playerMove == "c") {return;}
	}

	std::cout << "Your new position is: " << playerPos.x << " " << playerPos.y << "\n";

	if (player->inventory.empty() && rooms[playerPos.x][playerPos.y].item != nullptr) {
		player->inventory.push_back(rooms[playerPos.x][playerPos.y].item);
	}

	bool itemInventoryCheck = false;

	for (size_t i = 0; i < player->inventory.size(); ++i) {
		if (player->inventory[i] == rooms[playerPos.x][playerPos.y].item) {
			itemInventoryCheck = true;
			break;
		}
	}

	if (itemInventoryCheck == false) {
		player->inventory.push_back(rooms[playerPos.x][playerPos.y].item);
	}

	rooms[playerPos.x][playerPos.y].Description();

	for (int i = 0; i < enemies.size(); ++i) {
		if (enemies[i]->enemyPos.x == playerPos.x && enemies[i]->enemyPos.y == playerPos.y) {
			enemyEncounter(*enemies[i]);
		}
	}
}

void Game::useTurn() {
	while (true) {
		std::cout << "Choose an item to use (type the item): sword, healthPotion, or lantern. type C to cancel\n";
		std::string playerDecision;
		std::cin >> playerDecision;
		playerDecision[0] = std::tolower(static_cast<unsigned char>(playerDecision[0]));

		if (playerDecision == "c") { return; }

		for (size_t i = 0; i < player->inventory.size(); ++i) {
			if (playerDecision == player->inventory[i]->name) {
				if (player->inventory[i]->uses == 0) {
					std::cout << "You broke your item!\n";
					player->inventory.erase(player->inventory.begin() + i);
				}

				player->inventory[i]->use();

				if (player->inventory[i]->name == "health") {
					int healingAmount = randomInt(4, 8);
					player->healthPoints += healingAmount;
					std::cout << "You healed for " << healingAmount << ".\n";
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

void Game::enemyEncounter(Enemy enemy) {
	bool attackBool = false;

	while (true){
		std::cout << "\nTheres an enemy in this room! attack it or leave! (A or L).\n";
		std::string playerResponse;
		std::cin >> playerResponse;
		playerResponse[0] = std::tolower(static_cast<unsigned char>(playerResponse[0]));

		if (playerResponse == "l") {
			enemy.attackPlayer(player);
			std::cout << "You escaped.\n";
			return;
		}

		if (playerResponse == "a") {
			attackBool = true;
		}

		while (attackBool) {
			if (player->healthPoints <= 0) {
				leaveDungeon(true);
				return;
			}

			if (enemy.healthPoints <= 0) {
				enemy.death(*player);
				return;
			}

			for (int i = 0; i < player->inventory.size(); ++i) {
				if (player->inventory[i]->name == "sword") {
					enemy.healthPoints -= player->inventory[i]->damage;

					player->inventory[i]->use();
					break;
				}
			}

			enemy.healthPoints -= player->baseDamage;
			enemy.attackPlayer(player);

			std::cout << "You attacked the enemy! its new hp is: " << enemy.healthPoints << ".\n";
			std::cout << "Your hp is: " << player->healthPoints << ".\n";

			std::cout << "\nDo you want to Flee? y/n\n";
			std::string playerFleeResponse;
			std::cin >> playerFleeResponse;

			if (playerFleeResponse == "y") {
				enemy.attackPlayer(player);
				std::cout << "You escaped.\n";
				return;
			}

			std::cout << "You continue to fight!\n";
		}
	}
}

void Game::leaveDungeon(bool hasDied) {
	if (hasDied) {
		std::cout << "You died.\n";
	} else {
		std::cout << "You left the dungeon.\n" << "\n";
	}

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

