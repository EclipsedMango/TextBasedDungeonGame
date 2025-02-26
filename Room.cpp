#include "Room.h"

#include "HealthPotionItem.h"
#include "LanternItem.h"
#include "Util.h"

Room::Room(std::string description, Item *item) {
	this->descrip = description;
	this->item = item;
}

Room::~Room() {
	delete[] item;
}

void Room::Description() const {
	std::cout << descrip;
	int spawnItemNum = randomInt(1, 3);

	std::cout << "You found ";

	if (item != nullptr && spawnItemNum != 3) {
		item->description();
	}
	else {
		std::cout << "Nothing.\n";
	}
}

void Room::setDescription(std::string descript) {
	descrip = descript;
}


