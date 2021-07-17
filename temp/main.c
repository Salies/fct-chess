#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
#define BOARD_S (SIZE * SIZE)

typedef struct piece
{
    char type;
    char color;
    int row;
    int column;
} Piece;
void createBoard(Piece *Board[])
{
    for (int i = 0; i < BOARD_S; i++)
        Board[i] = (Piece *)(malloc(sizeof(Piece)));
}
void resetGame(Piece *Board[])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            Piece *aux = Board[i * SIZE + j];
            if (i == 0 || i == SIZE - 1)
            {
                aux->row = i;
                aux->column = j;
                if (j == 0 || j == SIZE - 1)
                    aux->type = 'r';
                else if (j == 1 || j == SIZE - 2)
                    aux->type = 'h';
                else if (j == 2 || j == SIZE - 3)
                    aux->type = 'b';
                else if (j == 3)
                    aux->type = 'q';
                else
                    aux->type = 'k';
            }
            else if (i == 1 || i == SIZE - 2)
                aux->type = 'p';
            else
                aux->type = '-';
        }
}
void printGame(Piece *Board[])
{
    for (short i = SIZE - 1; 0 <= i; i--)
    {
        printf("\n");
        for (short j = 0; j < SIZE; j++)
            printf("%c ", Board[i * SIZE + j]->type);
    }
    printf("\n");
}
Piece *getPieceAt(Piece *Board[], short i, short j)
{
    return Board[i * SIZE + j];
}
void movePiece(Piece *Board[], Piece *piece, short i, short j)
{
    short r = piece->row;
    short c = piece->column;
    piece->row = r;
    piece->column = c;
    Board[i * SIZE + j]->type = piece->type;
    Board[r * SIZE + c]->type = '-';
}
void capture(Piece *piece)
{
    if (piece->color == 'w')
        insertList(blackList, piece);
    else
        insertList(whiteList, piece);
}
insertList(List *list, Piece *piece) {}
int main()
{
    Piece *board[BOARD_S];
    createBoard(board);
    resetGame(board);
    printGame(board);
    movePiece(board, board[4], 3, 5);
    printGame(board);
}