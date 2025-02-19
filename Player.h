#pragma once

#include <vector>
#include <iostream>

class Player {
public:
	Player() = default;
	~Player() = default;

	void sortSpells();
	void learnSpell();
	bool findSpell(std::string spell);

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