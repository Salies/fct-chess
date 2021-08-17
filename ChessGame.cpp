#include "ChessGame.h"
#include <QDebug>

std::vector<std::array<int, 2>> ChessGame::getValidMoves(int piece, int x, int y) {
	std::vector<std::array<int, 2>> v;
	if (piece % 6 == 5) { // TODO peão
		if(piece == 5)
			v = { {x, y - 1} };
		else
			v = { {x, y + 1} };
	}

	piece = piece % 6;

	switch (piece) {
	case 0:
		v = {
				{x + 1, y + 1},
				{x + 1, y    },
				{x + 1, y - 1},
				{x    , y + 1},
				{x    , y - 1},
				{x - 1, y + 1},
				{x - 1, y    },
				{x - 1, y - 1}
		};
		break;
	case 1:

		break;
	case 3:
	int xoff = 7
	for(i = -xoff; i < xoff; i++){
	int yoff = 7
		v.push()
	}
		break;
	}
				
	v.push()

	
	std::array<std::vector<std::array<int, 2>>, 6> offsets = {
		{
			{ // 0 King
				{1, 1},
				{-1, -1},
				{1, -1},
				{-1, 1},
				{0, 1},
				{0, -1},
				{0, -1}
			},
			{ //1 Queen
				{7, 0},
				{-7, 0},
				{0, 7},
				{0, -7},
				{7, 7},
				{-7, -7},
				{-7, 7},
				{7, -7}
			},
			{ //2 Tower
				{7, 0},
				{-7, 0},
				{0, 7},
				{0, -7}
			},
			{ //3 Bishop
				{7, 7},
				{7, -7},
				{-7, 7},
				{-7, -7}
			},
			{ //4 Knight
				{2, 1},
				{2, -1},
				{-2, 1},
				{-2, -1},
				{1, 2},
				{1, -2},
				{-1, 2},
				{-1, -2}
			},
			{ //5 Pawn
				{1, 0}
			}
		}
	};

	//std::vector<std::array<int, 2>> v = offsets[piece % 6];
	std::vector<std::array<int, 2>> res;
	std::array<int, 2> aux;
	qDebug() << "====";
	for(int i = 0; i < v.size(); i++){
		aux = v[i];
		aux[0] += x;
		aux[1] += y;

		if (aux[0] < 0)
			aux[0] = 0;
		else if (aux[0] > 7)
			aux[0] = 7;
		
		if (aux[1] < 0)
			aux[1] = 0;
		else if (aux[1] > 7)
			aux[1] = 7;

		if (aux[0] == x && aux[1] == y)
			continue;
		

		qDebug() << aux[0] << aux[1];
		// remove iguais
		// se for onde ela já está, remove
		//qDebug() << aux[0] << aux[1];
	}

	return res;
}
