#include <random>
#include "RMXRandom.h"

int getRandomNumber(int min, int max)
{

	std::random_device generator;
	std::uniform_int_distribution<int> distribution(min, max);
	int result = distribution(generator);
	return result;

}