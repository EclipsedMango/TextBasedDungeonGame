#include "Game.h"

using namespace std;

Game::Game() {
	this->player = new Player;

	for (int i = 0; i < RandomInt(14, 24); ++i) {
		enemies.push_back(new Enemy);
	}

	for (int i = 0; i < roomRows; ++i) {
		for (int j = 0; j < roomColumn; ++j) {
			int randomDescNum = RandomInt(0, 9);
			int roomHaveItem = RandomInt(0, 2);
			int randomItemNum = RandomInt(0, 4);

			rooms[i][j].SetDescription(descriptions[randomDescNum]);

			if (roomHaveItem == 1) {
				CreationOfItem(rooms[i][j]);
			} else {
				rooms[i][j].item = nullptr;
			}
		}
	}
}

void Game::CreationOfItem(Room& room) {
	int randomItemNum = RandomInt(1, 5);

	switch (randomItemNum) {
	case 1:
		items.push_back(new SwordItem);
		break;
	case 2:
		items.push_back(new HealthPotionItem);
		break;
	case 3:
		items.push_back(new Lamp);
		break;
	case 4:
		items.push_back(new BoxOfDonuts);
		break;
	case 5:
		items.push_back(new Cat);
		break;
	}

	room.item = items.back();
}

Game::~Game() {
	for (int i = 0; i < enemies.size(); ++i) {
		delete enemies[i];
	}

	for (int i = 0; i < items.size(); ++i) {
		delete items[i];
	}

	delete player;
}

void Game::Run() {
	player->SortSpells();

	std::cout << "Type " << LIME << "play" << WHITE << " to play" << CYAN << " DungeonGameTheGame." << WHITE << "\n";
	std::string reply;
	std::cin >> reply;

	if (reply != "play") {
		std::cout << "You didn't type play. Goodbye!\n";
		delete player;
		return;
	}

	bool thingy = false;

	if (reply == "play") {
		thingy = true;
	}

	std::cout << "\n" << "These are your base stats:\n"
		<< GRAY "level: " << CYAN << player->level << "\n"
		<< GRAY "HP: " << LIGHTGREEN << player->healthPoints << "\n"
		<< GRAY "Damage: " << RED << player->baseDamage << "\n" WHITE;

	rooms[playerPos.x][playerPos.y].playerHasVisited = true;

	while (thingy) {
		if (player->movesRemaining <= 0) {
			std::cout << "\nYou ran of of moves.\n";
			LeaveDungeon(false);
			return;
		}

		if (player->healthPoints <= 0) {
			LeaveDungeon(true);
			return;
		}

		std::cout << "\n";
		DrawMap();

		std::cout << "\n"
			<< GRAY "Choose an action to do. type (" BWHITE "1, 2, 3, 4, 5, or 6" GRAY ").\n"
			<< BWHITE "1: " GRAY "Move.\n"
			<< BWHITE "2: " GRAY "Use Item.\n"
			<< BWHITE "3: " GRAY "Open Inventory.\n"
			<< BWHITE "4: " GRAY "Check Spells.\n"
			<< BWHITE "5: " GRAY "Show Stats.\n"
			<< BWHITE "6: " GRAY "Leave Dungeon.\n" WHITE;

		std::string playerDecision;
		std::cin >> playerDecision;
		std::cout << "\n";

		if (playerDecision == "1") {
			MoveTurn();
		}

		if (playerDecision == "2") {
			UseTurn();
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
			std::cout << GRAY "Type a" PURPLE " spell" GRAY " to see if you have it.\n" WHITE;
			std::cout << DARKGRAY "Hint! you have Fireball and Teleport by default!\n" WHITE;
			std::string playerReply;
			std::cin >> playerReply;

			if (player->FindSpell(playerReply)) {
				std::cout << GRAY "You have " << WHITE << playerReply << ".\n";
			} else {
				std::cout << GRAY "You dont have " << WHITE << playerReply << ".\n";
			}
		}

		if (playerDecision == "5") {
			std::cout << "Statistics:\n"
				<< GRAY "Player level: " << CYAN << player->level << "\n"
				<< GRAY "Player HP: " << LIGHTGREEN << player->healthPoints << "\n"
				<< GRAY "Player Damage: " << RED << player->baseDamage << "\n" WHITE;
		}

		if (playerDecision == "6") {
			LeaveDungeon(false);
			return;
		}
	}
}

void Game::MoveTurn() {
	while (true) {
		std::cout << GRAY "Type" BWHITE " N, E, S, W" GRAY " to move. or" BWHITE " C" GRAY" to cancel\n" WHITE;
		std::string playerMove;
		std::cin >> playerMove;
		playerMove[0] = std::tolower(static_cast<unsigned char>(playerMove[0]));
		std::cout << "\n";

		if (playerMove == "n" && playerPos.y > 0) {
			playerPos.y -= 1;
			break;
		}

		if (playerMove == "e" && playerPos.x < 10) {
			playerPos.x += 1;
			break;
		}

		if (playerMove == "s" && playerPos.y < 10) {
			playerPos.y += 1;
			break;
		}

		if (playerMove == "w" && playerPos.x > 0) {
			playerPos.x -= 1;
			break;
		}

		if (playerMove == "c") {return;}
	}

	player->movesRemaining -= 1;
	std::cout << GRAY "Your new position is: " << BWHITE << playerPos.x << " " << playerPos.y << "\n\n";

	if (!rooms[playerPos.x][playerPos.y].playerHasVisited) {
		if (player->inventory.empty() && rooms[playerPos.x][playerPos.y].item != nullptr) {
			player->inventory.push_back(rooms[playerPos.x][playerPos.y].item);
		}

		bool itemInventoryCheck = false;

		for (int i = 0; i < player->inventory.size(); ++i) {
			if (rooms[playerPos.x][playerPos.y].item != nullptr && player->inventory[i]->id == rooms[playerPos.x][playerPos.y].item->id) {
				itemInventoryCheck = true;
				break;
			}
		}

		if (itemInventoryCheck == false && rooms[playerPos.x][playerPos.y].item != nullptr) {
			player->inventory.push_back(rooms[playerPos.x][playerPos.y].item);
		}

		rooms[playerPos.x][playerPos.y].Description();

		for (int i = 0; i < enemies.size(); ++i) {
			if (enemies[i]->enemyPos.x == playerPos.x && enemies[i]->enemyPos.y == playerPos.y) {
				EnemyEncounter(*enemies[i]);
			}
		}

		rooms[playerPos.x][playerPos.y].playerHasVisited = true;
	} else {
		std::cout << "You have visited this room already. Theres nothing to find.\n";
	}
}

void Game::UseTurn() {
	while (true) {
		std::cout << GRAY "Type an item to use it: "
			BWHITE "sword, healthpotion, lamp, boxofdonuts or cat. " GRAY "type " BWHITE "C " GRAY "to cancel\n" WHITE;
		std::string playerDecision;
		std::cin >> playerDecision;
		playerDecision[0] = std::tolower(static_cast<unsigned char>(playerDecision[0]));

		if (playerDecision == "c") { return; }

		for (size_t i = 0; i < player->inventory.size(); ++i) {
			if (playerDecision == player->inventory[i]->name) {
				if (player->inventory[i]->uses <= 0) {
					std::cout << "You broke your item!\n";
					player->inventory.erase(player->inventory.begin() + i);
					return;
				}

				player->inventory[i]->Use();

				if (player->inventory[i]->name == "healthpotion") {
					int healingAmount = RandomInt(4, 8);
					player->healthPoints += healingAmount;
					std::cout << "You healed for " << healingAmount << ".\n";
				}

				return;
			}
		}

		std::cout << "\nYou don't have that item!\n";
	}
}

void Game::DrawMap() {

	std::cout << "=================================\n";
	for (int i = 0; i < roomColumn; ++i) {
		for (int j = 0; j < roomRows; ++j) {
			std::string out = (rooms[j][i].item == nullptr) ? "[ ]" : "[+]";
			if (j == playerPos.x && i == playerPos.y) {
				out = "[X]";
			}

			if (out == "[X]") {
				std::cout << GRAY "[" << BWHITE "X" << GRAY "]";
			} else if (out == "[+]") {
				std::cout << GRAY "[" << GOLD "+" << GRAY "]";
			} else {
				std::cout << GRAY << out;
			}
		}
		std::cout << "\n";
	}
	std::cout << WHITE "=================================\n";
}

void Game::EnemyEncounter(Enemy enemy) {
	bool attackBool = false;

	while (true){

		std::cout << "\n=================================\n";

		std::cout << GRAY "\nTheres an " << DARKRED << "enemy " GRAY "in this room! "
			WHITE "attack " GRAY "it or " WHITE "leave" GRAY "! (" BWHITE "A or L" GRAY ").\n" WHITE;
		std::string playerResponse;
		std::cin >> playerResponse;

		bool firstAttack = false;

		if (playerResponse == "L") {
			enemy.AttackPlayer(player);
			std::cout << "You escaped.\n";
			return;
		}

		if (playerResponse == "A") {
			attackBool = true;
			firstAttack = true;
		}

		while (attackBool) {
			if (player->healthPoints <= 0) {
				return;
			}

			if (enemy.healthPoints <= 0) {
				enemy.Death(player);
				return;
			}

			if (!firstAttack) {
				std::cout << GRAY "\nDo you want to Flee? " DARKGREEN "y" GRAY "/" DARKRED "n\n" WHITE;
				std::string playerFleeResponse;
				std::cin >> playerFleeResponse;

				if (playerFleeResponse == "y") {
					std::cout << "\n";
					enemy.AttackPlayer(player);
					std::cout << GRAY "\nYou escaped.\n" WHITE;
					return;
				}

				std::cout << GRAY "\nYou continue to fight!\n" WHITE;
			}

			std::cout << "\n=================================\n";

			if (!player->inventory.empty()) {
				for (int i = 0; i < player->inventory.size(); ++i) {
					if (player->inventory[i]->name == "sword") {
						enemy.healthPoints -= player->inventory[i]->damage;
						player->inventory[i]->Use();
						break;
					}
				}
			}

			std::cout << "\n";
			enemy.healthPoints -= player->baseDamage;
			enemy.AttackPlayer(player);

			std::cout << GRAY "\nYou attacked the enemy! its new hp is: " << LIGHTGREEN << enemy.healthPoints << GRAY ".\n";
			std::cout << "Your hp is: " << LIGHTGREEN << player->healthPoints << GRAY ".\n" WHITE;

			firstAttack = false;
		}
	}
}

void Game::LeaveDungeon(bool hasDied) {
	if (hasDied) {
		std::cout << "You " << RED "died" << WHITE ".\n";
	} else {
		std::cout << "You " << DARKGREEN "left" << WHITE " the dungeon.\n";
	}

	std::cout << DARKGRAY "=================================\n" WHITE;

	std::cout << "Statistics:\n"
		<< GRAY "level: " << CYAN << player->level << "\n"
		<< GRAY "HP: " << LIGHTGREEN << player->healthPoints << "\n"
		<< GRAY "Damage: " << RED << player->baseDamage << "\n" WHITE;

	std::cout << DARKGRAY "=================================\n" WHITE;

	std::cout << "\nLoot you left with:\n" << "\n";

	if (!player->inventory.empty()) {
		for (int i = 0; i < player->inventory.size(); ++i) {
			std::cout << player->inventory[i]->name << "\n";
		}

	} else {
		std::cout << "Nothing.\n";
	}

	std::cout << DARKGRAY "\n=================================\n" WHITE;

	std::cout << GOLD "\nGold" WHITE " you earned: " << GOLD << player->gold << WHITE << "\n";
	std::cout << DARKGREEN "GG," WHITE " I hope you had" CYAN " fun!\n" WHITE;
}

