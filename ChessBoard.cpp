#include "ChessBoard.h"
#include "ChessSquare.h"
#include "ChessGame.h"
#include <QHeaderView>

char ChessBoard::a[6] = { 'K', 'Q', 'R', 'B', 'N', 'P' };

ChessBoard::ChessBoard(bool whites) {
	horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed); // previne o tabuleiro de ser redimensionado
	verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	setColumnCount(8);
	setRowCount(8);
	setShowGrid(false);
	setFocusPolicy(Qt::NoFocus);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setStyleSheet("QTableWidget::item:selected{ background-color: #42adf5; color: red;}");

	QStringList l = { "h", "g", "f", "e", "d", "c", "b", "a" };
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
	hashCalc = new ZobHash();

	connect(this, &ChessBoard::cellClicked, this, &ChessBoard::squareClicked);
}

void ChessBoard::resetBoard() {
	podeJogar = true;
	vaiJogar = false;
	vezBranca = true;
	posPiece = {};
	tabelaHash.clear();
	lastPlay.clear();
	board = { {
		{8, 10, 9, 7, 6, 9, 10, 8},
		{11, 11, 11, 11, 11, 11, 11, 11},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{5, 5, 5, 5, 5, 5, 5, 5},
		{2, 4, 3, 1, 0, 3, 4, 2}
	} };

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			setPiece(i, j, board[i][j]);
			item(i, j)->setBackgroundColor(((i + j) % 2) ? QColor(118, 150, 86) : QColor(238, 238, 210));
		}
	}
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
	if (!podeJogar) return;

	if (!posPiece.empty()) {
		if (board[x][y] == board[posPiece[0]][posPiece[1]]) {
			return;
		}
	}

	for (std::array<int, 2> aux : lastPlay) {
		item(aux[0], aux[1])->setBackgroundColor(((aux[0] + aux[1]) % 2) ? QColor(118, 150, 86) : QColor(238, 238, 210));
	}

	if (board[x][y] == -1 || vaiJogar) { // se clica em casa vazia ou vai Jogar
		if (!lastPlay.contains(std::array<int, 2>({ x, y }))) { // se a jogada for inválida, cancela
			lastPlay.clear();
			posPiece = {};
			vaiJogar = false;
			return;
		} // senão, é uma casa de movimentação
	}

	if (vaiJogar) {
		emit(played(board[posPiece[0]][posPiece[1]], posPiece[0], posPiece[1], x, y, board[x][y]));
		if (board[x][y] != -1 && board[x][y] % 6 == 0) { // xeque mate
			emit(fim("Xeque-mate"));
			podeJogar = false;
		}
		setPiece(x, y, board[posPiece[0]][posPiece[1]]);
		setPiece(posPiece[0], posPiece[1], -1);
		board[x][y] = board[posPiece[0]][posPiece[1]];
		board[posPiece[0]][posPiece[1]] = -1;
		vaiJogar = false;
		vezBranca = !vezBranca;
		uint64_t ha = hashCalc->hash(board);
		if (tabelaHash.count(ha) == 0) { // se o elemento não existe na tabela hash, inserí-lo
			tabelaHash.insert({ ha, 0 });
		}
		else {
			tabelaHash[ha] = tabelaHash[ha] + 1;
			if (tabelaHash[ha] == 2) {
				emit(fim("Empate"));
				podeJogar = false;
			}
		}
		return;
	}

	if ((vezBranca && board[x][y] > 5) || (!vezBranca && board[x][y] < 6)) return;

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
	lastPlay = QVector<std::array<int, 2>>::fromStdVector(v);
}

std::array<std::array<int, 8>, 8> ChessBoard::getBoard() {
	return board;
}