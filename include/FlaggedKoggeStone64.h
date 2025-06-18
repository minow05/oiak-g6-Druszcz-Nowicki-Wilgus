
#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDKOGGESTONE64_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDKOGGESTONE64_H
#include "FlaggedAdder.h"
#include <cinttypes>
#include <vector>
#include <cmath>
#include <iostream>

#define SIZE 64

class FlaggedKoggeStone64 : public FlaggedAdder {
private:
    std::bitset<64> A, B, G, P, S, K, H; // a, b, generate, propagate, sum, kill, halfsum
    bool C = 0; // C_in
    std::vector<uint8_t> flags;
    void computeGeneratePropagate() override;
    void computeFlaggedPrefixTree() override;
    void computeSum() override;
public:
    FlaggedKoggeStone64(uint64_t x, uint64_t y, uint64_t flags, bool Cin);
    void printDebug() const;
    void setFlags(std::bitset<64> flags);
};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDKOGGESTONE64_H
