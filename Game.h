#pragma once

#include "Player.h"
#include <iostream>

#include "Enemy.h"
#include "HealthPotionItem.h"
#include "LanternItem.h"
#include "Room.h"
#include "SwordItem.h"
#include "Util.h"

class Game {
public:
	void run();
	void moveTurn();
	void useTurn();
	void drawMap();
	void enemyEncounter(Enemy enemy);
	void leaveDungeon(bool hasDied);

	Game();
	~Game();
private:
	static const int roomRows = 11;
	static const int roomColumn = 11;

	Room rooms[roomRows][roomColumn] = {};
	Player* player;

	std::vector<Enemy*> enemies = {};

	std::vector<std::string> descriptions = {
		"It's cold, dark, and large. Broken and old furniture litters the old room. ",
		"Your torches light reflects off the wet and damp walls. ",
		"As you enter a breeze follows sending a chill down your spine. ",
		"The room is filled with old chests and antique furniture. ",
		"A thick layer of dust and webs cover the old, decaying room. ",
		"You hear echoes of rats scurrying across the room. ",
		"Old moldy floor boards creek as you take a step. ",
		"Your steps echo through out the large room. ",
		"Old broken gear is spread throughout the dusty room. ",
		"The room seems empty, further exploration is needed. "
	};

	std::vector<Item*> items = {
		new HealthPotionItem(),
		new LanternItem(),
		new SwordItem()
	};
};
