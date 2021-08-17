#pragma once
#include <vector>
#include <array>
#include <stack>
class ChessGame
{
public:
	static std::vector<std::array<int, 2>> getValidMoves(int piece, int x, int y, std::array<std::array<int, 8>, 8> board);
private:
	static bool canCapture(int p1, int p2);
	static bool inBounds(int a);
};

