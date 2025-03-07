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

	void AttackPlayer(Player *player);
	void Death(Player *player);

	int healthPoints = 20;
	int baseDamage = 2;
	int level = 1;

	EnemyPos enemyPos = {RandomInt(1, 10), RandomInt(1, 10) };
};
