#include "Cat.h"

Cat::Cat() {
	this->id = randomInt(0, 10000);
	this->name = "cat";
	this->uses = 999;
}

void Cat::description() const {
	std::vector<std::string> descriptions = {
		"an orange cat",
		"a small kitten",
		"a very clean cat",
		"a tuxedo cat",
		"a cat"
	};

	std::cout << descriptions[randomInt(0, 4)] << "\n";
}

void Cat::use() {
	purring = !purring;

	if (purring) {
		std::cout << "You pet the cat, its now purring.\n";
	} else {
		std::cout << "You pet the cat, its no longer purring.\n";
	}
}