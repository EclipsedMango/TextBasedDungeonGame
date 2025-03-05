#pragma once
#include "Item.h"
#include "Util.h"

#include <vector>
#include <iostream>

class LanternItem : public Item {
public:
	LanternItem();
	void description() const override;
	void use() override;

	bool turnedOn = false;
};
