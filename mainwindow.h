#pragma once

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMainWindow>
#include "PlayList.h"
#include "StatusBar.h"
#include "ChessBoard.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);

private:
    QWidget* centralWidget;
    QVBoxLayout* centralLayout;
    StatusBar* statusBar;
    ChessBoard* board;
    void createChessBoard();
    void crateStatusBar();
public slots:
    void teste(int x, int y);
};
