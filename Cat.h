#pragma once
#include "Item.h"
#include "Util.h"

#include <vector>
#include <iostream>

class Cat : public Item {
public:
	Cat();
	void Description() const override;
	void Use() override;

	bool purring = false;
};