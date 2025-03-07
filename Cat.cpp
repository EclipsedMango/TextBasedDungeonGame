#include "Cat.h"

Cat::Cat() {
	this->id = RandomInt(0, 10000);
	this->name = "cat";
	this->uses = 999;
}

void Cat::Description() const {
	std::vector<std::string> descriptions = {
		"an orange cat",
		"a small kitten",
		"a very clean cat",
		"a tuxedo cat",
		"a cat"
	};

	std::cout << descriptions[RandomInt(0, 4)] << "\n";
}

void Cat::Use() {
	purring = !purring;

	if (purring) {
		std::cout << "You pet the cat, its now purring.\n";
	} else {
		std::cout << "You pet the cat, its no longer purring.\n";
	}
}