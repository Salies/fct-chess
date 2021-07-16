#include "mainwindow.h"
#include "ChessBoard.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setStyleSheet("background-color: #312e2b;");
    setWindowTitle("FCT-CHESS");
    resize(556, 556);

    centralWidget = new QWidget;
    centralLayout = new QVBoxLayout;
    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);

    createChessBoard();
    //https://stackoverflow.com/questions/16468235/resize-window-to-fit-content
    //adjustSize();
}

void MainWindow::createChessBoard() {
    QVBoxLayout* board_layout = new QVBoxLayout;
    ChessBoard* board = new ChessBoard(true);
    board_layout->addWidget(board);

    //QTableWidget *board = new QTableWidget(12, 3, this);

    centralLayout->addLayout(board_layout);
}
