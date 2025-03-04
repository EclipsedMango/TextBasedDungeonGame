#include "Enemy.h"

#include "Util.h"

void Enemy::attackPlayer(Player *player) {
	int randomHitChance = randomInt(0, 4);

	if (randomHitChance == 0) {
		int damageDone = baseDamage + randomInt(2, 4);
		player->healthPoints -= damageDone;
		std::cout << "The enemy attacked and landed it hit for: " << damageDone << ".\n";
	} else {
		std::cout << "The enemy attacked and missed.\n";
	}
}

void Enemy::death(Player player) {
	int randomGold = randomInt(5, 10) * level;
	player.gold += randomGold;
	std::cout << "You killed an enemy and gained " << randomGold << " Gold.\n";
}

