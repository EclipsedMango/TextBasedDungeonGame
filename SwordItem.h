#pragma once
#include "Item.h"
#include "Util.h"

#include <iostream>
#include <vector>

class SwordItem : public Item {
public:
	SwordItem();
	void Description() const override;
	void Use() override;
};
