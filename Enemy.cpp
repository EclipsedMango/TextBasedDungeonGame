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
		std::cout << "The enemy attacked and landed it hit for: " << damageDone << ".\n";
	} else {
		std::cout << "The enemy attacked and missed.\n";
	}
}

void Enemy::death(Player* player) {
	int randomGold = randomInt(5, 10) * level;
	player->gold += randomGold;
	std::cout << "You killed an enemy and gained " << randomGold << " Gold.\n";
}

