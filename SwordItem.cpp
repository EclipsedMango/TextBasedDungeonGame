#include "SwordItem.h"

#include <iostream>
#include <string>
#include <vector>

#include "Util.h"

SwordItem::SwordItem(int damage, int uses, int id) {
	this->damage = damage;
	this->uses = uses;
	this->id = id;
}

void SwordItem::description() const {
	std::vector<std::string> descriptions = {
		"a rusty	steel sword.",
		"an old knights sword.",
		"an average looking sword.",
		"a dull but large sword.",
		"a long sword."
	};

	std::cout << descriptions[randomInt(0, 4)];
}

void SwordItem::use() {

}

void SwordItem::equip() {

}

