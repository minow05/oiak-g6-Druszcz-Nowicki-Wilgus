
#include "../include/FlaggedKoggeStone64.h"

FlaggedKoggeStone64::FlaggedKoggeStone64(uint64_t x, uint64_t y, uint64_t flags, bool Cin) {
    this->size = 64;
    this->levels = std::ceil(std::log2(size));
    C = Cin;
    K = flags;
    for (int i = 0; i < size; ++i) {
        A[i] = (x >> i) & 1;
        B[i] = (y >> i) & 1;
    }

    computeGeneratePropagate();
    computeFlaggedPrefixTree();
    computeSum();
}

void FlaggedKoggeStone64::computeGeneratePropagate() {
    for (int i = 0; i < size; ++i) {
        G[i] = A[i] & B[i];
        P[i] = A[i] ^ B[i];
        H[i] = A[i] ^ B[i];
        // Kill signal - when flag is set, it kills the carry propagation
        for (int index : flags){
            K[index] = true;
        }
    }
}

void FlaggedKoggeStone64::computeFlaggedPrefixTree() {
//    (G[i], P[i]) = black_node(G[i], P[i], G[i - 2^s], P[i - 2^s])
    for (int j = 0; j < levels; j++){
        for (int i = (1 << j); i < size; i++){
            int index = i - (1 << j); //i - 2^j
            if (K[i] != 1){
                G[i] = (G[i] | (P[i] & G[index]));
                P[i] = (P[i] & P[index]);
            }
        }
    }

}

void FlaggedKoggeStone64::computeSum() {
    S[0] = H[0] ^ C;
    for (int i = 1; i < size; ++i) {
        S[i] = H[i] ^ (G[i-1] | P[i-1] & C);
    }
}

void FlaggedKoggeStone64::printDebug() const {
    std::cout << S << '\n';
//    std::cout << C << '\n';
//    std::cout << P << '\n';
//    std::cout << G << '\n';
}

void FlaggedKoggeStone64::setFlags(std::bitset<64> flags) {
    K = flags;
}
