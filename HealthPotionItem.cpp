#include "HealthPotionItem.h"

HealthPotionItem::HealthPotionItem() {
	this->id = RandomInt(0, 10000);
	this->name = "healthpotion";
	this->uses = 2;
}

void HealthPotionItem::Description() const {
	std::vector<std::string> descriptions = {
		"an old potent health potion.",
		"a heal potion in pristine condition.",
		"a long vial filled with a potion of health.",
		"a flask filled with a health potion",
		"a clean health potion"
	};

	std::cout << descriptions[RandomInt(0, 4)] << "\n";
}

void HealthPotionItem::Use() {
	uses = std::max(uses - 1, 0);
	std::cout << "You drank a health potion\n";
}
