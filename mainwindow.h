#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <stack>
#include <map>
#include "PlayList.h"
#include "StatusBar.h"
#include "ChessBoard.h"
#include "BoardPlayer.h"
#include "jogada.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
private:
    BoardPlayer* machine, * player;
    QWidget* centralWidget;
    QVBoxLayout* centralLayout;
    StatusBar* statusBar;
    ChessBoard* board;
    PlayList* play_list;
    QPushButton* salvar, *reiniciar;
    std::stack<Jogada> jogadas;
    std::stack<int> pCapturadas;
    void createChessBoard();
    void crateStatusBar();
public slots:
    void jogada(int piece, int xi, int yi, int xf, int yf, int capture);
    void fimdejogo(QString tipo);
    void salvarFn();
    void reiniciarFn();
};
