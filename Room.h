#pragma once
#include <string>
#include "Item.h"

class Room {
public:
	Room() = default;
	Room(std::string description, Item* item);
	virtual ~Room();

	void Description() const;
	void setDescription(std::string descript);

	Item* item;
	bool playerHasVisited = false;

private:
	std::string descrip;
};
