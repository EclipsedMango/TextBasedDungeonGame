#pragma once
#include "Item.h"
#include "Util.h"

#include <vector>
#include <iostream>

class Cat : public Item {
public:
	Cat();
	void description() const override;
	void use() override;

	bool purring = false;
};