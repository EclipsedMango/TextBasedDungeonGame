#pragma once
#include "Item.h"
#include "Player.h"
#include "Util.h"

class SwordItem : public Item {
public:
	SwordItem();
	void description() const override;
	void use() override;
};
