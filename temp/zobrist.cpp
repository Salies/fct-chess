#include <iostream>
#include <map>

typedef struct piece
{
    char type;
    bool black;
} Piece;

std::map<char, short> piecelist = {
    {'K', 0},
    {'Q', 1},
    {'R', 2},
    {'B', 3},
    {'N', 4},
    {'P', 5}
};

short get_piece_code(Piece p){
    if(p.black)
        return 6 + piecelist[p.type];
    return piecelist[p.type];
}

int main(void){
    Piece p1;
    p1.type = 'K';
    p1.black = false;

    std::cout << get_piece_code(p1);

    return 0;
}