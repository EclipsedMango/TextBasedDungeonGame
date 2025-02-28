#pragma once

#include <vector>
#include <iostream>

#include "Player.h"

inline struct {
	int x = 5;
	int y = 5;
} enemyPos;

class Enemy {
public:
	Enemy() = default;
	~Enemy() = default;

	void attackPlayer(Player player);
	void death(Player player);

	int healthPoints = 20;
	int baseDamage = 2;
	int level = 1;
};
