#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDADDER_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDADDER_H
#include <bitset>

class FlaggedAdder{
protected:
    int size = 0;
    void computeGeneratePropagate();
    void computeFlaggedPrefixTree();
    void computeSum();
public:
    void printDebug() const;
    void setFlags(int index);
};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDADDER_H
