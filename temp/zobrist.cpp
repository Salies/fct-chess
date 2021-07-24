#include <iostream>
#include <string>
#include <random>
//#include <bits/stdc++.h>

char piece_list[6] = {'K', 'Q', 'R', 'B', 'N', 'P'};

/*
0/6 - reis
1/7 - damas
2/8 - torres
3/9 - bispos
4/10 - cavalos
5/11 - peões
6/12 - reis que podem rocar => não implementado
7/13 - peões que podem capturar en passant => não implementado
*/

int board[8][8] = {
    {-1, -1, -1, 6, -1, -1, -1, -1},
    {-1, 8, -1, -1, -1, -1, 7, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-1, 11, -1, -1, -1, -1, 5, -1},
    {-1, -1, -1, -1, -1, 5, -1, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {5, -1, -1, -1, 3, -1, -1, 1},
    {-1, -1, -1, -1, 4, -1, -1, 0}
};

std::string get_piece_code(unsigned short p){
    if(p > 6) 
        return "B" + std::string(1, piece_list[p - 7]);
    return "W" + std::string(1, piece_list[p - 1]);
}

uint64_t z_table[8][8][16];
std::mt19937 mt_rand(6661); // wapOqjQ4r_M

uint64_t rnd_bitstr(){
    std::uniform_int_distribution<uint64_t> dist(0, UINT64_MAX);
    return dist(mt_rand);
}

void init_zobrist(){
    for(int i= 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            for(int k = 0; k < 16; k++)
                z_table[i][j][k] = rnd_bitstr();
}

uint64_t hash(int b[8][8]){
    uint64_t h = 0;
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(b[i][j] != -1)
                h ^= z_table[i][j][b[i][j]];

    return h;
}

int main(void){
    std::cout << get_piece_code(7) << "\n";

    init_zobrist();

    std::cout << hash(board);

    return 0;
}