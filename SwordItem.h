#pragma once
#include "Item.h"
#include "Player.h"
#include "Util.h"

class SwordItem : public Item {
public:
	SwordItem();
	void description() const override;
	void use() override;

	int damage = randomInt(2, 6);
	int uses = randomInt(1, 6);
};
