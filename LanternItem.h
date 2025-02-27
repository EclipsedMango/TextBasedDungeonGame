#pragma once
#include "Item.h"
#include "Player.h"
#include "Util.h"

class LanternItem : public Item {
public:
	LanternItem();
	void description() const override;
	void use() override;

	bool turnedOn = false;
};
