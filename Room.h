#pragma once
#include "Item.h"

#include <iostream>
#include <string>

class Room {
public:
	Room() = default;
	Room(std::string descript, Item* item);
	virtual ~Room() = default;

	void Description() const;
	void setDescription(std::string descript);

	Item* item;
	bool playerHasVisited = false;

private:
	std::string description;
};
