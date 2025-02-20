#pragma once
#include "Item.h"
#include "Player.h"

class HealthPotionItem : public Item {
	HealthPotionItem() = default;
	explicit HealthPotionItem(int uses, int id);
	void description() const override;
	void use() override;
	void equip(Player player);

	bool used = false;
	int uses = 0;
	int id = 0;
};
