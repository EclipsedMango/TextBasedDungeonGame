#include "BoxOfDonuts.h"

BoxOfDonuts::BoxOfDonuts() {
	this->id = RandomInt(0, 10000);
	this->name = "boxofdonuts";
	this->uses = count;
}

void BoxOfDonuts::Description() const {
	std::vector<std::string> descriptions{
		"an old box of donuts.",
		"a fresh box of jam filled donuts.",
		"a moldy box of donuts.",
		"a box of donuts.",
		"a box filled with different donuts."
	};

	std::cout << descriptions[RandomInt(0, 4)] << "\n";
}

void BoxOfDonuts::Use() {
	uses = std::max(uses - 1, 0);
	count = std::max(count - 1, 0);
	std::cout << "You ate a donut, you now have " << count << " donuts.\n";
}