#include <iostream>
#include <string>
#include <random>
//#include <bits/stdc++.h>

char piece_list[6] = {'K', 'Q', 'R', 'B', 'N', 'P'};

std::string get_piece_code(unsigned short p){
    if(p > 6) 
        return "B" + std::string(1, piece_list[p - 7]);
    return "W" + std::string(1, piece_list[p - 1]);
}

uint64_t z_table[8][8][12];
std::mt19937 mt_rand(6661); // wapOqjQ4r_M

uint64_t rnd_bitstr(){
    std::uniform_int_distribution<uint64_t> dist(0, UINT64_MAX);
    return dist(mt_rand);
}

void init_zobrist(){
    for(int i= 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            for(int k = 0; k < 12; k++)
                z_table[i][j][k] = rnd_bitstr();
}

int main(void){
    std::cout << get_piece_code(7) << "\n";

    init_zobrist();

    std::cout << z_table[0][0][0];

    return 0;
}