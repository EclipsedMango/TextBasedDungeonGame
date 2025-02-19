#include "Player.h"

#include <algorithm>
#include <random>

#include "Util.h"

void Player::sortSpells() {
	std::ranges::sort(allSpells);
}

void Player::learnSpell() {
	int spellNum = randomInt(0, 7);

	const std::string& spellName = allSpells[spellNum];

	if (!findSpell(spellName)) {
		std::cout << "You learnt " << spellName << ".\n";
		spells.push_back(spellName);
	}
	else {
		std::cout << "You already learnt this spell!\n";
	}
}

bool Player::findSpell(std::string spell) {
	int low = 0;
	int high = static_cast<int>(spells.size());

	while (high != low) {
		const int i = (low + high) / 2;
		const int compareString = spell.compare(spells[i]);

		if (compareString == 0) {
			return true;
		}

		if (compareString > 0) {
			low = i;
		}
		else {
			high = i;
		}

		if (high - low == 1) {
			return false;
		}
	}

	return false;
}

