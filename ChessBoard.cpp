#include "ChessBoard.h"
#include "ChessSquare.h"
#include <QHeaderView>

ChessBoard::ChessBoard(bool whites){
	horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed); // previne o tabuleiro de ser redimensionado
	verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	setColumnCount(8);
	setRowCount(8);
	setShowGrid(false);
	setFocusPolicy(Qt::NoFocus);
	setSelectionMode(QAbstractItemView::SingleSelection);
	setStyleSheet("QTableWidget::item:selected{ background-color: #42adf5 }");

	QStringList l = {"h", "f", "f", "e", "d", "c", "b", "a"};
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