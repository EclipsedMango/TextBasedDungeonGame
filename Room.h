#pragma once
#include <string>
#include "Item.h"

class Room {
	Room(std::string description, Item item);
	virtual ~Room() = default;

	void enterRoom();
	void Description() const;
};
