#include "mainwindow.h"
#include "BoardPlayer.h"
#include <QFontDatabase>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setStyleSheet("background-color: #312e2b");
    setWindowTitle("FCT-CHESS");
    //resize(547, 631);
    //setFixedSize(QSize(685, 631));
    //setSizeConstraint(QLayout::SetFixedSize)

    centralWidget = new QWidget;
    centralLayout = new QVBoxLayout;
    centralWidget->setFixedSize(QSize(683, 666));
    centralWidget->setLayout(centralLayout);

    setCentralWidget(centralWidget);

    createChessBoard();
    crateStatusBar();
    //https://stackoverflow.com/questions/16468235/resize-window-to-fit-content
    //adjustSize();
}

void MainWindow::createChessBoard() {
    QHBoxLayout* play_area = new QHBoxLayout;
    QVBoxLayout* board_layout = new QVBoxLayout, *list_layout = new QVBoxLayout;
    board = new ChessBoard(true);
    BoardPlayer* machine = new BoardPlayer(true), *player = new BoardPlayer(false);

    board_layout->addLayout(machine);
    board_layout->addWidget(board);
    board_layout->addLayout(player);

    play_area->addLayout(board_layout);

    // criando barra de jogadas
    PlayList* play_list = new PlayList;
    QLabel* l = new QLabel("Lista de jogadas");
    l->setStyleSheet("margin-top:35px; font-size:14px; color: #fff; font-weight:600");
    list_layout->addWidget(l);
    list_layout->addWidget(play_list);
    list_layout->addStretch();

    play_area->addLayout(list_layout);

    centralLayout->addLayout(play_area);
}

void  MainWindow::crateStatusBar() {
    QFrame* hFrame = new QFrame;
    hFrame->setFrameShape(QFrame::HLine);
    hFrame->setFrameShadow(QFrame::Raised);
    statusBar = new StatusBar();
    centralLayout->addWidget(hFrame);
    centralLayout->addLayout(statusBar);
}

void MainWindow::teste(int x, int y) {
    
}

// TODO: otimizar cores?