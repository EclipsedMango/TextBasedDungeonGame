#include "Enemy.h"

void Enemy::AttackPlayer(Player *player) {
	int randomHitChance = RandomInt(0, 4);
	int damageDone = baseDamage + RandomInt(2, 4);

	if (enemyPos.x > 8 || enemyPos.x < 4 || enemyPos.y > 8 || enemyPos.y < 4) {
		level += 1;
		randomHitChance = RandomInt(0, 2);
		damageDone = baseDamage + RandomInt(3, 5);
	}

	if (randomHitChance == 0) {
		player->healthPoints -= damageDone;
		std::cout << GRAY "The enemy attacked and landed it hit for: " << RED << damageDone << WHITE ".\n";
	} else {
		std::cout << GRAY "The enemy attacked and " DARKGREEN "missed.\n" WHITE;
	}
}

void Enemy::Death(Player* player) {
	int randomGold = RandomInt(5, 10) * level;
	player->gold += randomGold;
	std::cout << GRAY "You " DARKRED "killed " GRAY "an enemy and gained " GOLD << randomGold << " Gold.\n" WHITE;
}

