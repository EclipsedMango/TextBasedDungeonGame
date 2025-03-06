#pragma once
#include "Item.h"
#include "Util.h"

#include <vector>
#include <iostream>

class Lamp : public Item {
public:
	Lamp();
	void description() const override;
	void use() override;

	bool turnedOn = false;
};
