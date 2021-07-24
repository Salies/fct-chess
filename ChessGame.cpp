#include "ChessGame.h"

std::vector<std::array<int, 2>> ChessGame::getValidMoves(int piece, int x, int y) {
	std::vector<std::array<int, 2>> v;

	switch (piece) {
		case 0:
			v.push_back({ x + 1, y + 1 });
			v.push_back({ x - 1, y - 1 });
			v.push_back({ x + 1, y - 1 });
			v.push_back({ x - 1, y + 1 });
			v.push_back({ x, y + 1 });
			v.push_back({ x, y - 1 });
			break;
	}
}
