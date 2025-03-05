#pragma once
#include "Item.h"
#include "Util.h"

#include <iostream>
#include <vector>

class HealthPotionItem : public Item {
public:
	HealthPotionItem();
	void description() const override;
	void use() override;
};
