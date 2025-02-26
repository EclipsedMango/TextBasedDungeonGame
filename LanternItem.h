#pragma once
#include "Item.h"
#include "Player.h"
#include "Util.h"

class LanternItem : public Item {
public:
	LanternItem() = default;
	void description() const override;
	void use() override;
	void equip(Player player);

	bool turnedOn = false;
	int uses = randomInt(1, 6);
};
