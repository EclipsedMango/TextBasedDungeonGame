#include "Enemy.h"

void Enemy::attackPlayer(Player *player) {
	int randomHitChance = randomInt(0, 4);
	int damageDone = baseDamage + randomInt(2, 4);

	if (enemyPos.x > 8 || enemyPos.x < 4 || enemyPos.y > 8 || enemyPos.y < 4) {
		level += 1;
		randomHitChance = randomInt(0, 2);
		damageDone = baseDamage + randomInt(3, 5);
	}

	if (randomHitChance == 0) {
		player->healthPoints -= damageDone;
		std::cout << GRAY "The enemy attacked and landed it hit for: " << RED << damageDone << WHITE ".\n";
	} else {
		std::cout << GRAY "The enemy attacked and " DARKGREEN "missed.\n" WHITE;
	}
}

void Enemy::death(Player* player) {
	int randomGold = randomInt(5, 10) * level;
	player->gold += randomGold;
	std::cout << GRAY "You " DARKRED "killed " GRAY "an enemy and gained " GOLD << randomGold << " Gold.\n" WHITE;
}

