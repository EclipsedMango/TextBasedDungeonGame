#include "Room.h"

#include "HealthPotionItem.h"
#include "LanternItem.h"
#include "SwordItem.h"
#include "Util.h"

Room::Room(std::string description, Item *item) {

}

void Room::Description() const {
	std::vector<std::string> descriptions = {
		"It's cold, dark, and large. Broken and old furniture litters the old room. ",
		"Your torches light reflects off the wet and damp walls. ",
		"As you enter a breeze follows sending a chill down your spine. ",
		"The room is filled with old chests and antique furniture. ",
		"A thick layer of dust and webs cover the old, decaying room. ",
		"You hear echoes of rats scurrying across the room. ",
		"Old moldy floor boards creek as you take a step. ",
		"Your steps echo through out the large room. ",
		"Old broken gear is spread throughout the dusty room. ",
		"The room seems empty, further exploration is needed. "
	};

	std::cout << descriptions[randomInt(0, 9)];
}

void Room::enterRoom() {
	Description();

	// Generate Random Item.
	if (randomInt(0, 2) % 2 == 0) {
		int randomItem = randomInt(1, 3);
		Item* item = new Item;

		std::cout << "You found ";

		switch (randomItem) {
		case 0:
			item = new SwordItem;
			item->description();
		case 1:
			item = new HealthPotionItem;
			item->description();
		case 2:
			item = new LanternItem;
			item->description();
		default: std::cout << "Failed to make item.\n";
		}
	}
}


