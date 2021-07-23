#pragma once
#include <QtWidgets/QTableWidgetItem>
class ChessSquare : public QTableWidgetItem
{
public:
	ChessSquare(bool dark);
private:
	static char a[6];
};

