#include <iostream>
#include <array>
#include <string>
#include <bitset>
#include <vector>

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

std::array<std::array<uint64_t, 8>, 8> bitboards = { {
		{0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
} };

uint64_t pawn(int x, int y, bool up){ // up = brancas, num tabuleiro não invertível
    int f = -1;
    if(up) f = 1;

    std::bitset<64> b(0);
    std::size_t s = 1;

    s = (8 * (y + (1*f))) + x;
    b[s] = 1;

    if(y == 1 || y == 6){
        s = (8 * (y + (2*f))) + x;
        b[s] = 1;
    };

    //std::cout << b;

    return b.to_ullong();
}

void print_bitboard(int i, int j){
    std::cout << std::bitset<64>(bitboards[i][j]) << "\n";
}

int main(void){
    //print_bitboard(0, 0);
    bitboards[6][1] = pawn(6, 1, false);
    std::cout << bitboards[6][1];

    return 0;
}