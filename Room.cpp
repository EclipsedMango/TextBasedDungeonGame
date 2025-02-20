#include "Room.h"

#include "HealthPotionItem.h"
#include "LanternItem.h"
#include "SwordItem.h"
#include "Util.h"

Room::Room(std::string description, Item item) {

}

void Room::Description() const {

}

void Room::enterRoom() {
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


