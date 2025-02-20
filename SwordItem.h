#pragma once
#include "Item.h"
#include "Player.h"

class SwordItem : public Item {
public:
	SwordItem() = default;
	explicit SwordItem(int damage, int uses, int id);
	void description() const override;
	void use() override;
	void equip(Player player);

	int damage = 0;
	int uses = 0;
	int id = 0;
};
