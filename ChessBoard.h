#pragma once

#include <QtWidgets/QTableWidget>
class ChessBoard : public QTableWidget 
{
public:
	ChessBoard(bool whites);
	void setInitPos();
private:
	static char a[6];
	void setPiece(int x, int y, int piece);
};

