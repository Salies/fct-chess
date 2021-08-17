#include "ChessGame.h"

bool ChessGame::canCapture(int p1, int p2) {
	if (p2 == -1) return false;
	return (((p1 > 5) && (p2 < 6)) || ((p1 < 6) && (p2 > 5)));
}

bool ChessGame::inBounds(int a) {
	return !(a > 7 || a < 0);
}

//TODO USAR BOARD AT NÃO BOARD[]
std::vector<std::array<int, 2>> ChessGame::getValidMoves(int piece, int x, int y, std::array<std::array<int, 8>, 8> board) {
	int i, j, auxp = piece % 6;
	std::vector<std::array<int, 2>> v;
	std::vector<std::array<int, 2>> aux;
	switch (auxp) {
	case 0:
		aux = {
				{x + 1, y + 1},
				{x + 1, y    },
				{x + 1, y - 1},
				{x    , y + 1},
				{x    , y - 1},
				{x - 1, y + 1},
				{x - 1, y    },
				{x - 1, y - 1}
		};
		
		for (i = 0; i < aux.size(); i++) {
			if (aux[i][0] > 7 || aux[i][0] < 0 || aux[i][1] > 7 || aux[i][1] < 0 || (board[aux[i][0]][aux[i][1]] != -1 && !canCapture(piece, board[aux[i][0]][aux[i][1]]))) {
				continue;
			}
			v.push_back(aux[i]);
		}
		break;
	case 1:
		// TORRE
		for (i = x + 1; i <= 7; i++) { // movimentos de baixo
			if (board[i][y] != -1) {
				if (canCapture(piece, board[i][y])) {
					aux.push_back({ i, y });
					v.push_back({ i, y });
				}
				break;
			}
			aux.push_back({ i, y });
			v.push_back({ i, y });
		}
		for (i = x - 1; i >= 0; i--) { // movimentos de cima
			if (board[i][y] != -1) {
				if (canCapture(piece, board[i][y])) {
					aux.push_back({ i, y });
					v.push_back({ i, y });
				}
				break;
			}
			aux.push_back({i, y});
			v.push_back({ i, y });
		}
		for (i = y + 1; i <= 7; i++) {
			if (board[x][i] != -1) {
				if (canCapture(piece, board[x][i])) {
					aux.push_back({ x, i });
					v.push_back({ x, i });
				}
				break;
			}
			aux.push_back({ x, i });
			v.push_back({ x, i });
		}
		for (i = y - 1; i >= 0; i--) {
			if (board[x][i] != -1) {
				if (canCapture(piece, board[x][i])) {
					aux.push_back({ x, i });
					v.push_back({ x, i });
				}
				break;
			}
			aux.push_back({ x, i });
			v.push_back({ x, i });
		}
		// BISPO
		i = x + 1; j = y + 1;
		while (i <= 7 && j <= 7) { // diagonal baixo direita
			if (board[i][j] != -1) {
				if (canCapture(piece, board[i][j])) {
					aux.push_back({ i, j });
					v.push_back({ i, j });
				}
				break;
			}
			aux.push_back({ i, j });
			v.push_back({ i, j });
			i++; j++;
		}

		i = x + 1; j = y - 1;
		while (i <= 7 && j >= 0) { // diagonal baixo esquerda
			if (board[i][j] != -1) {
				if (canCapture(piece, board[i][j])) {
					aux.push_back({ i, j });
					v.push_back({ i, j });
				}
				break;
			}
			aux.push_back({ i, j });
			v.push_back({ i, j });
			i++; j--;
		}

		i = x - 1; j = y + 1;
		while (i >= 0 && j <= 7) { // diagonal baixo esquerda
			if (board[i][j] != -1) {
				if (canCapture(piece, board[i][j])) {
					aux.push_back({ i, j });
					v.push_back({ i, j });
				}
				break;
			}
			aux.push_back({ i, j });
			v.push_back({ i, j });
			i--; j++;
		}

		i = x - 1; j = y - 1;
		while (i >= 0 && j >= 0) { // diagonal baixo esquerda
			if (board[i][j] != -1) {
				if (canCapture(piece, board[i][j])) {
					aux.push_back({ i, j });
					v.push_back({ i, j });
				}
				break;
			}
			aux.push_back({ i, j });
			v.push_back({ i, j });
			i--; j--;
		}
		break;
	case 2:
		for (i = x + 1; i <= 7; i++) { // movimentos de baixo
			if (board[i][y] != -1) {
				if (canCapture(piece, board[i][y])) {
					aux.push_back({ i, y });
					v.push_back({ i, y });
				}
				break;
			}
			aux.push_back({ i, y });
			v.push_back({ i, y });
		}
		for (i = x - 1; i >= 0; i--) { // movimentos de cima
			if (board[i][y] != -1) {
				if (canCapture(piece, board[i][y])) {
					aux.push_back({ i, y });
					v.push_back({ i, y });
				}
				break;
			}
			aux.push_back({ i, y });
			v.push_back({ i, y });
		}
		for (i = y + 1; i <= 7; i++) {
			if (board[x][i] != -1) {
				if (canCapture(piece, board[x][i])) {
					aux.push_back({ x, i });
					v.push_back({ x, i });
				}
				break;
			}
			aux.push_back({ x, i });
			v.push_back({ x, i });
		}
		for (i = y - 1; i >= 0; i--) {
			if (board[x][i] != -1) {
				if (canCapture(piece, board[x][i])) {
					aux.push_back({ x, i });
					v.push_back({ x, i });
				}
				break;
			}
			aux.push_back({ x, i });
			v.push_back({ x, i });
		}
		break;
	case 3:
		i = x + 1; j = y + 1;
		while (i <= 7 && j <= 7) { // diagonal baixo direita
			if (board[i][j] != -1) {
				if (canCapture(piece, board[i][j])) {
					aux.push_back({ i, j });
					v.push_back({ i, j });
				}
				break;
			}
			aux.push_back({ i, j });
			v.push_back({ i, j });
			i++; j++;
		}

		i = x + 1; j = y - 1;
		while (i <= 7 && j >= 0) { // diagonal baixo esquerda
			if (board[i][j] != -1) {
				if (canCapture(piece, board[i][j])) {
					aux.push_back({ i, j });
					v.push_back({ i, j });
				}
				break;
			}
			aux.push_back({ i, j });
			v.push_back({ i, j });
			i++; j--;
		}
		
		i = x - 1; j = y + 1;
		while (i >= 0 && j <= 7) { // diagonal baixo esquerda
			if (board[i][j] != -1) {
				if (canCapture(piece, board[i][j])) {
					aux.push_back({ i, j });
					v.push_back({ i, j });
				}
				break;
			}
			aux.push_back({ i, j });
			v.push_back({ i, j });
			i--; j++;
		}

		i = x - 1; j = y - 1;
		while (i >= 0 && j >= 0) { // diagonal baixo esquerda
			if (board[i][j] != -1) {
				if (canCapture(piece, board[i][j])) {
					aux.push_back({ i, j });
					v.push_back({ i, j });
				}
				break;
			}
			aux.push_back({ i, j });
			v.push_back({ i, j });
			i--; j--;
		}

		break;
	case 4:
		aux = {
			{x + 2, y + 1},
			{x + 2, y - 1},
			{x + 1, y + 2},
			{x + 1, y - 2},
			{x - 1, y + 2},
			{x - 1, y - 2},
			{x - 2, y + 1},
			{x - 2, y - 1}
		};

		for (i = 0; i < aux.size(); i++) {
			if (aux[i][0] > 7 || aux[i][0] < 0 || aux[i][1] > 7 || aux[i][1] < 0 || (board[aux[i][0]][aux[i][1]] != -1 && !canCapture(piece, board[aux[i][0]][aux[i][1]]))) {
				continue;
			}
			v.push_back(aux[i]);
		}
		break;
	case 5:
		int f = 1;
		if (piece == 5) f = -1; // peão branco
		aux.push_back({ x + f * 1, y });
		if ((piece == 11 && x == 1) || (piece == 5 && x == 6)) // se for a primeira jogada
			aux.push_back({ x + f * 2, y });

		if (inBounds(x + f * 1)) {
			if (inBounds(y + 1) && canCapture(piece, board[x + f * 1][y + 1]))
				v.push_back({ x + f * 1, y + 1 });

			if (inBounds(y - 1) && canCapture(piece, board[x + f * 1][y - 1]))
				v.push_back({ x + f * 1, y - 1 });
		}

		for (i = 0; i < aux.size(); i++) {
			if (aux[i][0] > 7 || aux[i][0] < 0 || aux[i][1] > 7 || aux[i][1] < 0 || board[aux[i][0]][aux[i][1]] != -1) {
				continue;
			}
			v.push_back(aux[i]);
		}

		break;
	};

	return v;
}
