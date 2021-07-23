#include "ChessBoard.h"
#include "ChessSquare.h"
#include <QHeaderView>

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
}

void ChessBoard::setInitPos() { //TODO: temporaria
	setPiece(0, 0, 8);
	setPiece(0, 7, 8);
	setPiece(0, 1, 10);
	setPiece(0, 6, 10);
	setPiece(0, 2, 9);
	setPiece(0, 5, 9);
	setPiece(0, 4, 6);
	setPiece(0, 3, 7);
	setPiece(7, 0, 2);
	setPiece(7, 7, 2);
	setPiece(7, 1, 4);
	setPiece(7, 6, 4);
	setPiece(7, 2, 3);
	setPiece(7, 5, 3);
	setPiece(7, 4, 0);
	setPiece(7, 3, 1);
	for (int i = 0; i < 8; i++) {
		setPiece(1, i, 11);
		setPiece(6, i, 5);
	}
}

void ChessBoard::setPiece(int x, int y, int piece) {
	QString t = "w";
	int p = piece;

	if (p > 5) {
		p -= 6;
		t = "b";
	}

	item(x, y)->setData(Qt::DecorationRole, QPixmap::fromImage(QImage(":/fctchess/qrc/pieces/" + t + QString(a[p]) + ".png")));
}