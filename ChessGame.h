#pragma once
#include <vector>
#include <array>
#include <stack>
class ChessGame
{
public:
	static std::vector<std::array<int, 2>> getValidMoves(int piece, int x, int y);
};

