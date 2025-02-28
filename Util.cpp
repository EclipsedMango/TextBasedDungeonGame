#include "Util.h"

#include <random>

int randomInt(const int firstValue, const int secondValue) {
	std::mt19937 gen(std::random_device{}());
	const int randNum = std::uniform_int_distribution<>(firstValue, secondValue)(gen);
	return randNum;
}
