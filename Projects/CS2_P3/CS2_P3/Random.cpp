#include "Random.h"
#include <ctime>
using std::uniform_int_distribution;
using std::uniform_real_distribution;

mt19937 Random::random(time(0));

int Random::Int(int min, int max)
{
	uniform_int_distribution<int> dist(min, max);

	return dist(random);
}