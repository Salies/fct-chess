#include "ChessSquare.h"

ChessSquare::ChessSquare(bool dark) {
	setBackground(dark ? QColor(118, 150, 86) : QColor(238, 238, 210));
}