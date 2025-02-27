#include "Room.h"

#include <iostream>

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

	std::cout << "You found ";

	if (item != nullptr) {
		item->description();
	}
	else {
		std::cout << "Nothing.\n";
	}
}

void Room::setDescription(std::string descript) {
	descrip = descript;
}


