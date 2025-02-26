#pragma once
#include "Item.h"
#include "Player.h"
#include "Util.h"

class HealthPotionItem : public Item {
public:
	HealthPotionItem() = default;
	void description() const override;
	void use() override;
	void equip(Player player);

	bool used = false;
	int uses = 1;
};
