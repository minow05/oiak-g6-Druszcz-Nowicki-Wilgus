
#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDKOGGESTONE64_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDKOGGESTONE64_H
#include "FlaggedAdder.h"
#include <cinttypes>
#include <vector>

#define SIZE 64

class FlaggedKoggeStone64 : public FlaggedAdder {
private:
    std::bitset<64> A, B, G, P, C, S, K; // a, b, generate, propagate, carry, sum, kill, (halfsum = P)
    std::vector<uint8_t> flags;
    int levels;
    void computeGeneratePropagate();
    void computeFlaggedPrefixTree();
    void computeSum();
public:
    FlaggedKoggeStone64(uint64_t x, uint64_t y);
    void printDebug() const;
    void setFlags(int index);
};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDKOGGESTONE64_H
