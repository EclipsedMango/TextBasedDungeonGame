#pragma once

#include <vector>
#include <iostream>

#include "Item.h"

inline struct {
	int x = 5;
	int y = 5;
} playerPos;

class Player {
public:
	Player() = default;
	~Player() = default;

	void sortSpells();
	void learnSpell();
	bool findSpell(std::string spell);

	std::vector<Item*> inventory;

	int healthPoints = 20;
	int baseDamage = 2;
	int level = 1;
	int gold = 0;
	int movesRemaining = 2;

private:
	std::vector<std::string> spells = {
		"Fireball",
		"Teleport"
	};
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
