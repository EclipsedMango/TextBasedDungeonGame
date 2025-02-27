#include "LanternItem.h"

#include "Util.h"

LanternItem::LanternItem() {
	this->id = randomInt(0, 10000);
}

void LanternItem::description() const {
	std::vector<std::string> descriptions{
		"a rusty but reliable lantern.",
		"an old bright lantern.",
		"a hand held lantern.",
		"a blindingly bright lantern.",
		"a dull old flame sits inside the lantern."
	};

	std::cout << descriptions[randomInt(0, 4)] << "\n";
}

void LanternItem::use() {
	turnedOn = !turnedOn;

	if (turnedOn) {
		std::cout << "The room brightens as you hold the lantern up.\n";
	}
}