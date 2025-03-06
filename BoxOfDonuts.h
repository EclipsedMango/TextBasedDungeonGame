#pragma once
#include "Item.h"
#include "Util.h"

#include <vector>
#include <iostream>

class BoxOfDonuts : public Item {
public:
	BoxOfDonuts();
	void description() const override;
	void use() override;

	int count = randomInt(2, 6);
};
