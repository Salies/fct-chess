#pragma once

#include <QtWidgets/QTableWidget>
#include <array>
#include <QVector>
#include "ZobHash.h"

class ChessBoard : public QTableWidget 
{
	Q_OBJECT
public:
	ChessBoard(bool whites);
	void resetBoard();
	std::array<std::array<int, 8>, 8> getBoard();
public slots:
	void squareClicked(int x, int y);
Q_SIGNALS:
	void played(int piece, int xi, int yi, int xf, int yf, int capture);
	void fim(QString tipo);
private:
	bool vaiJogar;
	bool vezBranca;
	bool podeJogar;
	// usa-se std::aray (C++) ao invés dos arrays de C p/ maior compatibilidade com POO
	std::array<std::array<int, 8>, 8> board;
	QVector<std::array<int, 2>> lastPlay;
	std::array<int, 2> posPiece;
	ZobHash* hashCalc;
	std::map<uint64_t, int> tabelaHash;
	static char a[6];
	void setPiece(int x, int y, int piece);
};

