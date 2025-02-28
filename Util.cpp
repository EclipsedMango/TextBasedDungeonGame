#include "Util.h"

#include <random>

int randomInt(int firstValue, int secondValue) {
	std::mt19937 gen(std::random_device{}());
	return std::uniform_int_distribution<>(firstValue, secondValue)(gen);
}
