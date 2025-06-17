#include <cmath>
#include "../include/FlaggedKoggeStone64.h"

FlaggedKoggeStone64::FlaggedKoggeStone64() {
    this->size = 64;
    this->levels = std::ceil(std::log2(size));
    computeGeneratePropagate();
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
}

void FlaggedKoggeStone64::computeSum() {

}

void FlaggedKoggeStone64::printDebug() const {

}

void FlaggedKoggeStone64::setFlags(int index) {

}
