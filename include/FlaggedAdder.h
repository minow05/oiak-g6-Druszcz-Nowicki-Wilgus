#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDADDER_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDADDER_H
#include <bitset>

class FlaggedAdder{
protected:
    int size = 0;
    int levels = 0;

    virtual void computeGeneratePropagate() = 0;

    virtual void computeFlaggedPrefixTree() = 0;

    virtual void computeSum() = 0;
public:
    void printDebug() const;
    void setFlags(int index);
};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FLAGGEDADDER_H
