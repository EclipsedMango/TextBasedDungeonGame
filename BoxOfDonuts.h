#pragma once
#include "Item.h"
#include "Util.h"

#include <vector>
#include <iostream>

class BoxOfDonuts : public Item {
public:
	BoxOfDonuts();
	void Description() const override;
	void Use() override;

	int count = RandomInt(2, 6);
};
