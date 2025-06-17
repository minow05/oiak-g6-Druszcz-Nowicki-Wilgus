#include <cmath>
#include <iostream>
#include "../include/FlaggedKoggeStone64.h"

FlaggedKoggeStone64::FlaggedKoggeStone64(uint64_t x, uint64_t y) {
    for (int i = 0; i < size; ++i) {
        A[i] = (x >> i) & 1;
        B[i] = (y >> i) & 1;
    }
    this->size = 64;
    this->levels = std::ceil(std::log2(size));
    computeGeneratePropagate();
    computeFlaggedPrefixTree();
    computeSum();
}

void FlaggedKoggeStone64::computeGeneratePropagate() {
    for (int i = 0; i < 8; ++i) {
        G[i] = A[i] & B[i];
        P[i] = A[i] ^ B[i];
        // Kill signal - when flag is set, it kills the carry propagation
        for (int index : flags){
            K[index] = true;
        }
    }
}

void FlaggedKoggeStone64::computeFlaggedPrefixTree() {
//    (G[i], P[i]) = black_node(G[i], P[i], G[i - 2^s], P[i - 2^s])
    for (int j = 0; j < levels; j++){
        for (int i = 1; i < size; i++){
//            G[i] = (G[i] | (P[i] & G[i-2^j])) & !K[i];
            G[i] = (G[i] | (P[i] & G[i-2^j]));
//            P[i] = (P[i] & P[i-2^j]) & !K[i];
            P[i] = (P[i] & P[i-2^j]);
        }
    }
    for (int i = 0; i < size; i++){
        C[i] = G[i] | P[i];
    }
}

void FlaggedKoggeStone64::computeSum() {
    for (int i = 0; i < size; ++i) {
        S[i] = P[i] ^ C[i];
    }
}

void FlaggedKoggeStone64::printDebug() const {
    for (int i = 0; i < size; ++i) {
        std::cout << S[i];
    }
    std::cout << '\n';

}

void FlaggedKoggeStone64::setFlags(int index) {

}
