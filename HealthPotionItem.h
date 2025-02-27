#pragma once
#include "Item.h"

class HealthPotionItem : public Item {
public:
	HealthPotionItem();
	void description() const override;
	void use() override;

	bool used = false;
	int uses = 1;
};
