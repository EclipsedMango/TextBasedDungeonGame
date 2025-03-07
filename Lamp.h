#pragma once
#include "Item.h"
#include "Util.h"

#include <vector>
#include <iostream>

class Lamp : public Item {
public:
	Lamp();
	void Description() const override;
	void Use() override;

	bool turnedOn = false;
};
