#include <iostream>
#include <array>
#include <string>
#include <bitset>

struct BOARDSAVE {
    uint64_t pos;
    uint64_t pieces_upper; // para dar suporte a sistemas de 32 bits
    uint64_t pieces_lower;
} board_save;

std::array<std::array<int, 8>, 8> board = { {
		{8, 10, 9, 7, 6, 9, 10, 8},
		{11, 11, 11, 11, 11, 11, 11, 11},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{-1, -1, -1, -1, -1, -1, -1, -1},
		{5, 5, 5, 5, 5, 5, 5, 5},
		{2, 4, 3, 1, 0, 3, 4, 2}
} };

void set_bits(uint64_t *bign, uint64_t val, int pos){
    *bign = *bign | (val << (pos * 4)); // OR direto pois bign é inicializado com 0
}

int main(void){
    int i = 0, j;

    BOARDSAVE bs;
    bs.pos = 0;
    bs.pieces_lower = 0;
    bs.pieces_upper = 0;

    for (; i < 4; i++) {
        for(j = 0; j < 8; j++){
            if(board[i][j] != -1){
                bs.pos |= 1ULL << (8 * i) + j;
                set_bits(&bs.pieces_lower, board[i][j], (8 * i) + j);
            }
        }
    }

    for (; i < 8; i++) {
        for(j = 0; j < 8; j++){
            if(board[i][j] != -1){
                bs.pos |= 1ULL << (8 * i) + j;
                set_bits(&bs.pieces_upper, board[i][j], (8 * (i - 8)) + j);
            }
        }
    }

    std::cout << bs.pos << "\n";
    std::cout << bs.pieces_lower << "\n";
    std::cout << bs.pieces_upper << "\n";

    return 0;
}