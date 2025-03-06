#include "Lamp.h"

Lamp::Lamp() {
	this->id = randomInt(0, 10000);
	this->name = "lamp";
	this->uses = randomInt(1, 4);
}

void Lamp::description() const {
	std::vector<std::string> descriptions{
		"a rusty but reliable lamp.",
		"an old bright lamp.",
		"a hand held lamp.",
		"a blindingly bright lamp.",
		"a dull old flame sits inside the lamp."
	};

	std::cout << descriptions[randomInt(0, 4)] << "\n";
}

void Lamp::use() {
	uses = std::max(uses - 1, 0);
	turnedOn = !turnedOn;

	if (turnedOn) {
		std::cout << "The room brightens as you hold the lamp up.\n";
	} else {
		std::cout << "The room darkens as you lower the lamp.\n";
	}
}