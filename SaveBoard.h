#pragma once
#include <array>
#include <stack>
#include "jogada.h"

class SaveBoard
{
public:
	static void save(std::array<std::array<int, 8>, 8> tabuleiro, std::stack<Jogada> jogadas, std::stack<int> capturas);
private:
	static void set_bits(uint64_t* bign, uint64_t val, int pos);
};