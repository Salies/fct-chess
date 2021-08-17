#include "ZobHash.h"

ZobHash::ZobHash() {
	mt_rand = std::mt19937(6661);

    // gera os tabuleiros
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 16; k++)
                z_table[i][j][k] = rnd_bitstr();
}

uint64_t ZobHash::rnd_bitstr(){
    std::uniform_int_distribution<uint64_t> dist(0, UINT64_MAX);
    return dist(mt_rand);
}

uint64_t ZobHash::hash(std::array<std::array<int, 8>, 8> b) {
    uint64_t h = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (b[i][j] != -1)
                h ^= z_table[i][j][b[i][j]];

    return h;
}