#pragma once
#include "Item.h"
#include "Player.h"
#include "Util.h"

class SwordItem : public Item {
public:
	SwordItem() = default;
	void description() const override;
	void use() override;
	void equip(Player player);

	int damage = randomInt(2, 6);
	int uses = randomInt(1, 6);
};
