#include "HealthPotionItem.h"

#include <iostream>

#include "Util.h"

HealthPotionItem::HealthPotionItem() {
	this->id = randomInt(0, 10000);
	this->name = "Health Potion";
	this->uses = 1;
}

void HealthPotionItem::description() const {
	std::vector<std::string> descriptions = {
		"an old potent health potion.",
		"a heal potion in pristine condition.",
		"a long vial filled with a potion of health.",
		"a flask filled with a health potion",
		"a clean health potion"
	};

	std::cout << descriptions[randomInt(0, 4)] << "\n";
}

void HealthPotionItem::use() {
	uses = std::max(uses - 1, 0);
	std::cout << "You drank a health potion\n";
}
