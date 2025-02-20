#include "HealthPotionItem.h"

#include "Util.h"

HealthPotionItem::HealthPotionItem(int uses, int id) {
	this->uses = uses;
	this->id = id;
}

void HealthPotionItem::description() const {
	std::vector<std::string> descriptions = {
		"an old potent health potion.",
		"a heal potion in pristine condition.",
		"a long vial filled with a potion of health.",
		"a flask filled with a health potion",
		"a clean health potion"
	};

	std::cout << descriptions[randomInt(0, 4)];
}

void HealthPotionItem::use() {
	used = true;
}

void HealthPotionItem::equip(Player player) {
	player.inventory.push_back(*this);
}
