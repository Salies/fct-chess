#include "ChessBoard.h"
#include "ChessSquare.h"
#include "ChessGame.h"
#include <QHeaderView>
#include <QDebug>

char ChessBoard::a[6] = { 'K', 'Q', 'R', 'B', 'N', 'P' };

ChessBoard::ChessBoard(bool whites){
	horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed); // previne o tabuleiro de ser redimensionado
	verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	setColumnCount(8);
	setRowCount(8);
	setShowGrid(false);
	setFocusPolicy(Qt::NoFocus);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setStyleSheet("QTableWidget::item:selected{ background-color: #42adf5; color: red;   }");

	QStringList l = {"h", "g", "f", "e", "d", "c", "b", "a"};
	QStringList n;

	for (int i = 0; i < 8; i++) {
		setColumnWidth(i, 64);
		setRowHeight(i, 64);
		n.append(QString::number((8 - i)));

		for (int j = 0; j < 8; j++) {
			setItem(i, j, new ChessSquare((i + j) % 2));
		}
	}

	if (whites) {
		l.sort();
		setVerticalHeaderLabels(n);
	};

	setHorizontalHeaderLabels(l);
	resetBoard();

	connect(this, &ChessBoard::cellClicked, this, &ChessBoard::squareClicked);
}

void ChessBoard::resetBoard() {
	vaiJogar = false;
	board = { {
		{8, 10, -1, 7, 6, 9, 10, -1},
		{11, -1, 11, 11, 11, 11, 11, 11},
		{-1, 11, -1, -1, -1, -1, -1, 8},
		{-1, -1, 3, 1, -1, 9, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, 5, -1, -1, -1},
		{5, 5, 5, 5, -1, 5, 5, 5},
		{2, 4, -1, -1, 0, 3, 4, 2}
	} };

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			setPiece(i, j, board[i][j]);
}

void ChessBoard::setPiece(int x, int y, int piece) {
	if (piece == -1) {
		item(x, y)->setData(Qt::DecorationRole, NULL);
		return;
	}

	QString t = "w";

	if (piece > 5) {
		piece -= 6;
		t = "b";
	}

	item(x, y)->setData(Qt::DecorationRole, QPixmap::fromImage(QImage(":/fctchess/qrc/pieces/" + t + QString(a[piece]) + ".png")));
}

void ChessBoard::squareClicked(int x, int y) {
	for (std::array<int, 2> aux : lastPlay) {
		item(aux[0], aux[1])->setBackgroundColor(((aux[0] + aux[1]) % 2) ? QColor(118, 150, 86) : QColor(238, 238, 210));
	}

	if (board[x][y] == -1) {
		if (!vaiJogar && !(std::find(lastPlay.begin(), lastPlay.end(), std::array<int, 2>({ x, y })) != lastPlay.end())) { // é uma jogada válida da peça anterior
			vaiJogar = false;
			return;
		}
	};

	if (vaiJogar) {
		int piece = board[posPiece[0]][posPiece[1]];
		QString t = "w";
		if (piece > 5) {
			piece -= 6;
			t = "b";
		}
		board[x][y] = board[posPiece[0]][posPiece[1]];
		board[posPiece[0]][posPiece[1]] = -1;
		item(x, y)->setData(Qt::DecorationRole, QPixmap::fromImage(QImage(":/fctchess/qrc/pieces/" + t + QString(a[piece]) + ".png")));
		item(posPiece[0], posPiece[1])->setData(Qt::DecorationRole, NULL);
		vaiJogar = false;
		return;
	}

	std::vector<std::array<int, 2>> v = ChessGame::getValidMoves(board[x][y], x, y, board);

	for (std::array<int, 2> aux : v) {
		if (board[aux[0]][aux[1]] == -1) {
			item(aux[0], aux[1])->setBackgroundColor(QColor(246, 246, 105));
			continue;
		}
		item(aux[0], aux[1])->setBackgroundColor(QColor(235, 97, 80));
	}

	posPiece = {x, y};
	vaiJogar = true;
	lastPlay = v;
}