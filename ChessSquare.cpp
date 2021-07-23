#include "ChessSquare.h"

char ChessSquare::a[6] = { 'K', 'Q', 'R', 'B', 'N', 'P' };

ChessSquare::ChessSquare(bool dark) {
	setBackground(dark ? QColor(118, 150, 86) : QColor(238, 238, 210));
	//setTextAlignment(Qt::AlignHCenter);
	setTextAlignment(Qt::AlignCenter);
}