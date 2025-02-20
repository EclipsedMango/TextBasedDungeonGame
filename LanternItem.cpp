#include "LanternItem.h"

#include "Util.h"

LanternItem::LanternItem(int uses, int id) {
	this->uses = uses;
	this->id = id;
}

void LanternItem::description() const {
	std::vector<std::string> descriptions{
		"a rust but reliable lantern.",
		"an old bright lantern.",
		"a hand held lantern.",
		"a blindingly bright lantern.",
		"a dull old flame sits inside the lantern."
	};

	std::cout << descriptions[randomInt(0, 4)];
}

void LanternItem::use() {
	turnedOn = !turnedOn;

	if (turnedOn) {
		std::cout << "The room brightens as you hold the lantern up.\n";
	}
}

void LanternItem::equip(Player player) {
	player.inventory.push_back(*this);
}
