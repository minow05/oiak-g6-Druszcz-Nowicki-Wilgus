
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
    std::bitset<64> A, B, G, P, S, K; // a, b, generate, propagate, sum, kill, halfsum
    bool inc, cmp = 0; // increment, negate
    void computeGeneratePropagate() override;
    void computeFlaggedPrefixTree() override;
    void computeSum() override;
public:
    FlaggedKoggeStone64(uint64_t x, uint64_t y, bool cmp, bool inc);
    void printDebug() const;
};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDKOGGESTONE64_H
