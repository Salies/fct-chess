#pragma once
#include <random>
#include <array>
class ZobHash
{
public:
	ZobHash();
	uint64_t hash(std::array<std::array<int, 8>, 8> b);
private:
	std::mt19937 mt_rand;
	uint64_t z_table[8][8][16];
	uint64_t rnd_bitstr();
};

