#pragma once

#include <vector>
#include <iostream>

#include "Player.h"
#include "Util.h"

struct EnemyPos {
	int x;
	int y;
};

class Enemy {
public:
	Enemy() = default;
	~Enemy() = default;

	void attackPlayer(Player player);
	void death(Player player);

	int healthPoints = 20;
	int baseDamage = 2;
	int level = 1;

	EnemyPos enemyPos = {randomInt(1, 10), randomInt(1, 10) };
};
