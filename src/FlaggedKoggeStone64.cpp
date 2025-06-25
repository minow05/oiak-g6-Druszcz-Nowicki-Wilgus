
#include "../include/FlaggedKoggeStone64.h"

FlaggedKoggeStone64::FlaggedKoggeStone64(uint64_t x, uint64_t y, bool cmp, bool inc) {
    this->size = 64;
    this->levels = std::ceil(std::log2(size));
    this->cmp = cmp;
    this->inc = inc;
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
        K[i] = A[i] | B[i];
    }
}

void FlaggedKoggeStone64::computeFlaggedPrefixTree() {
//    (G[i], P[i]) = black_node(G[i], P[i], G[i - 2^s], P[i - 2^s])
    for (int j = 0; j < levels; j++){
        for (int i = (1 << j); i < size; i++){
            int index = i - (1 << j); //i - 2^j
            G[i] = (G[i] | (K[i] & G[index]));
            K[i] = K[i] & K[index];
        }
    }

}

void FlaggedKoggeStone64::computeSum() {
    S[0] = inc ^ P[0];
    for (int i = 1; i < size; i++){
        S[i] = ((K[i-1] & inc) | G[i-1])^(P[i] ^ cmp);
    }
     C[SIZE - 1] = G[SIZE - 1] | (K[SIZE - 1] & C[SIZE - 2]);
}

bool FlaggedKoggeStone64::getCarryOut() const {
    return C[SIZE-1];
}

void FlaggedKoggeStone64::printDebug(uint64_t x, uint64_t y) const {
    std::cout << "A     = " << std::bitset<64>(A) << "\n";
    std::cout << "B     = " << std::bitset<64>(B) << "\n";
    std::cout << "inc   = " << inc << "\n";
    std::cout << "cmp   = " << cmp << "\n";
    std::cout << "Sum   = " <<  S << "\n";
    std::cout << "Cout  = " << getCarryOut() << "\n";
}
