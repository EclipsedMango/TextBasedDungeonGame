#pragma once
#include "Item.h"

class SwordItem : public Item {
public:
	SwordItem(int damage, int uses, int id);
	void description() const override;
	void use() override;
	void equip();

	int damage = 0;
	int uses = 0;
	int id = 0;
};
