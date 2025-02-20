#pragma once

#include <vector>
#include <iostream>

#include "Item.h"

class Player {
public:
	Player() = default;
	~Player() = default;

	void sortSpells();
	void learnSpell();
	bool findSpell(std::string spell);

	std::vector<Item> inventory = {};

private:
	std::vector<std::string> spells;
	std::vector<std::string> allSpells = {
		"Fireball",
		"Magic Missile",
		"Teleport",
		"Enhanced Sword",
		"Enhanced Bow",
		"Wind Burst",
		"Arrow Volley",
		"Icicle Volley",
	};
};
