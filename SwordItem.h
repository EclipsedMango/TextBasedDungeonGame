#pragma once
#include "Item.h"
#include "Util.h"

#include <iostream>
#include <vector>

class SwordItem : public Item {
public:
	SwordItem();
	void description() const override;
	void use() override;
};
