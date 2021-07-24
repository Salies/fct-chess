#pragma once

#include <QtWidgets/QTableWidget>
#include <array>

class ChessBoard : public QTableWidget 
{
public:
	ChessBoard(bool whites);
	void resetBoard();
public slots:
	void squareClicked(int x, int y);
private:
	// usa-se std::aray (C++) ao invés dos arrays de C p/ maior compatibilidade com POO
	std::array<std::array<int, 8>, 8> board;
	static char a[6];
	void setPiece(int x, int y, int piece);
};

