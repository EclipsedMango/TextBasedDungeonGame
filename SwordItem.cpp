#include "SwordItem.h"

SwordItem::SwordItem() {
	this->id = RandomInt(0, 10000);
	this->name = "sword";
	this->uses = RandomInt(2, 5);
	this->damage = RandomInt(2, 6);
}

void SwordItem::Description() const {
	std::vector<std::string> descriptions = {
		"a rusty steel sword.",
		"an old knights sword.",
		"an average looking sword.",
		"a dull but large sword.",
		"a long sword."
	};

	std::cout << descriptions[RandomInt(0, 4)] << "\n";
}

void SwordItem::Use() {
	uses = std::max(uses - 1, 0);
	std::cout << "You swung the sword at a ferocious speed.\n";
}

