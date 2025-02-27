#include "SwordItem.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Util.h"

SwordItem::SwordItem() {
	this->id = randomInt(0, 10000);
	this->name = "sword";
	this->uses = randomInt(2, 5);
}


void SwordItem::description() const {
	std::vector<std::string> descriptions = {
		"a rusty steel sword.",
		"an old knights sword.",
		"an average looking sword.",
		"a dull but large sword.",
		"a long sword."
	};

	std::cout << descriptions[randomInt(0, 4)] << "\n";
}

void SwordItem::use() {
	uses = std::max(uses - 1, 0);
	std::cout << "You swung the sword at a ferocious speed.\n";
}

