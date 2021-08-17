#include "mainwindow.h"
#include <QFontDatabase>
#include <QString>
#include <QStringList>
#include "SaveBoard.h"

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
    connect(board, &ChessBoard::played, this, &MainWindow::jogada);
    connect(board, &ChessBoard::fim, this, &MainWindow::fimdejogo);
    //https://stackoverflow.com/questions/16468235/resize-window-to-fit-content
    //adjustSize();
}

void MainWindow::createChessBoard() {
    QHBoxLayout* play_area = new QHBoxLayout;
    QVBoxLayout* board_layout = new QVBoxLayout, *list_layout = new QVBoxLayout;
    board = new ChessBoard(true);
    machine = new BoardPlayer(true);
    player = new BoardPlayer(false);

    board_layout->addLayout(machine);
    board_layout->addWidget(board);
    board_layout->addLayout(player);

    play_area->addLayout(board_layout);

    // criando barra de jogadas
    salvar = new QPushButton("Salvar");
    reiniciar = new QPushButton("Reiniciar");
    salvar->setStyleSheet("background: #fff");
    reiniciar->setStyleSheet("background: #fff");
    play_list = new PlayList;
    QLabel* l = new QLabel("Lista de jogadas");
    l->setStyleSheet("margin-top:35px; font-size:14px; color: #fff; font-weight:600");
    list_layout->addWidget(l);
    list_layout->addWidget(play_list);
    list_layout->addStretch();
    list_layout->addWidget(reiniciar);
    list_layout->addWidget(salvar);

    play_area->addLayout(list_layout);

    centralLayout->addLayout(play_area);

    connect(salvar, &QPushButton::released, this, &MainWindow::salvarFn);
    connect(reiniciar, &QPushButton::released, this, &MainWindow::reiniciarFn);
}

void MainWindow::crateStatusBar() {
    QFrame* hFrame = new QFrame;
    hFrame->setFrameShape(QFrame::HLine);
    hFrame->setFrameShadow(QFrame::Raised);
    statusBar = new StatusBar();
    centralLayout->addWidget(hFrame);
    centralLayout->addLayout(statusBar);
}

void MainWindow::jogada(int piece, int xi, int yi, int xf, int yf, int capture) {
    QTableWidgetItem* item = new QTableWidgetItem();
    QString s = "brancas", s2;
    QStringList pecs = { "K", "Q", "R", "B", "K", "P"};
    QStringList posi = { "a", "b", "c", "d", "e", "f", "g", "h"};
    s2 = pecs[piece % 6] + posi[yf] + QString::number(8 - xf);
    int linha = play_list->rowCount();
    statusBar->setSide(false);
    if (piece > 5) {
        s = "pretas";
        statusBar->setSide(true);
    }
    item->setText(s);
    // atualiza as pilhas
    Jogada j;
    j.piece = piece;
    j.xi = xi;
    j.yi = yi;
    j.xf = xf;
    j.yf = yf;
    j.capture = capture;
    if (capture != -1) {
        pCapturadas.push(capture);
        if (capture > 5) { // peça preta capturada
            player->setCapturas(pecs[capture % 6]);
        }
        else {
            machine->setCapturas(pecs[capture % 6]);
        }
    }
    jogadas.push(j);

    // atualiza a interface
    play_list->setItem(linha - 1, 0, new QTableWidgetItem(s));
    play_list->setItem(linha - 1, 1, new QTableWidgetItem(s2));
    play_list->item(linha - 1, 0)->setBackgroundColor(Qt::white);
    play_list->item(linha - 1, 1)->setBackgroundColor(Qt::white);
    play_list->setRowCount(linha + 1);
    return;
}

void MainWindow::fimdejogo(QString tipo) {
    statusBar->mate(tipo);
}

void MainWindow::salvarFn() {
    SaveBoard::save(board->getBoard(), jogadas, pCapturadas);
}

void MainWindow::reiniciarFn() {
    while (!jogadas.empty()) { // limpa as pilhas
        jogadas.pop();
    }
    while (!pCapturadas.empty()) {
        pCapturadas.pop();
    }
    player->resetCapturas();
    machine->resetCapturas();
    board->resetBoard();
    statusBar->setSide(true);
    play_list->clearContents();
    play_list->setRowCount(1);
}

// TODO: otimizar cores?