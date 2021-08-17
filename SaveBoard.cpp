#include "SaveBoard.h"
#include <QTextStream>
#include <QFile>
#include <QString>

typedef struct {
    uint64_t pos;
    uint64_t pieces_upper; // para dar suporte a sistemas de 32 bits
    uint64_t pieces_lower;
} BoardSave;

void SaveBoard::save(std::array<std::array<int, 8>, 8> board, std::stack<Jogada> jogadas, std::stack<int> capturas) {
    QString saveString = "//===== TABULEIRO =====//\n";
    QFile caFile("relatorio.txt");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream outStream(&caFile);
    //outStream << "//===== TABULEIRO =====//\n";

    std::stack<Jogada> jAux = jogadas;
    std::stack<int> jCap = capturas;
    BoardSave bs;
    bs.pos = 0;
    bs.pieces_lower = 0;
    bs.pieces_upper = 0;

    int i = 0, j;
    for (; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] != -1) {
                bs.pos |= 1ULL << (8 * i) + j;
                set_bits(&bs.pieces_lower, board[i][j], (8 * i) + j);
            }
        }
    }

    for (; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] != -1) {
                bs.pos |= 1ULL << (8 * i) + j;
                set_bits(&bs.pieces_upper, board[i][j], (8 * (i - 8)) + j);
            }
        }
    }

    saveString.append(QString::number(bs.pos) + "\n" + QString::number(bs.pieces_upper) + "\n" + QString::number(bs.pieces_lower) + "\n");
    saveString.append("\n//===== JOGADAS =====//\n");

    QStringList c = { "a", "b", "c", "d", "e", "f", "g", "h" };
    QStringList p = { "K", "Q", "R", "B", "N", "P"};
    QString cor;
    Jogada jogAux;
    int capAux;
    while (!jAux.empty()) { // desempilha as jogadas
        jogAux = jAux.top();
        cor = (jogAux.piece > 5) ? "b" : "w";
        saveString.append(QString::number(jAux.size()) + ". " + cor + p[jogAux.piece % 6] + c[jogAux.yi] + QString::number(8 - jogAux.xi) + c[jogAux.yf] + QString::number(8 - jogAux.xf) + "\n");
        jAux.pop();
    }

    saveString.append("\n//===== CAPTURAS =====//\n");

    while (!jCap.empty()) { // desempilha as capturas
        capAux = jCap.top();
        cor = (capAux > 5) ? "b" : "w";
        saveString.append(cor + p[capAux % 6] + " ");
        jCap.pop();
    }

    outStream << saveString;
}

void SaveBoard::set_bits(uint64_t* bign, uint64_t val, int pos) {
    *bign = *bign | (val << (pos * 4)); // OR direto pois bign é inicializado com 0
}