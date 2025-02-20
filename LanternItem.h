#pragma once
#include "Item.h"
#include "Player.h"

class LanternItem : public Item {
public:
	LanternItem() = default;
	explicit LanternItem(int uses, int id);
	void description() const override;
	void use() override;
	void equip(Player player);

	bool turnedOn = false;
	int uses = 0;
	int id = 0;
};