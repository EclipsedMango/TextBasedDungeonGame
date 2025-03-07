#include "Room.h"

#include "Util.h"

Room::Room(std::string descript, Item *item) {
	this->description = descript;
	this->item = item;
}

void Room::Description() const {
	std::cout << description;

	std::cout << "You found ";

	if (item != nullptr) {
		item->Description();
	}
	else {
		std::cout << "Nothing.\n";
	}
}

void Room::SetDescription(std::string descript) {
	description = descript;
}


