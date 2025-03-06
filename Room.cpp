#include "Room.h"

#include "Util.h"

Room::Room(std::string descript, Item *item) {
	this->description = descript;
	this->item = item;
}

Room::~Room() {
	delete[] item;
}

void Room::Description() const {
	std::cout << description;

	std::cout << "You found ";

	if (item != nullptr) {
		item->description();
	}
	else {
		std::cout << "Nothing.\n";
	}
}

void Room::setDescription(std::string descript) {
	description = descript;
}


