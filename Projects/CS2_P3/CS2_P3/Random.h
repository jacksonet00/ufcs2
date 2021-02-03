#pragma once
#include <random>
using std::mt19937;
class Random
{
	static mt19937 random;
public:
	static int Int(int min, int max);
};

