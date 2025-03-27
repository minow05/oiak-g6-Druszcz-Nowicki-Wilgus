#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_HALFADDER_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_HALFADDER_H

#include "Bit.h"
#include "FundamentalCarryOperator.h"
#include "SumGenerator.h"

class HalfAdder {
public:
    HalfAdder(Bit x, Bit y, int column, std::vector<FundamentalCarryOperator*> fcos, SumGenerator* sumGenerator);
    void execute();
    int column;
private:
    Bit x, y;
    std::vector<FundamentalCarryOperator*> fcos;
    SumGenerator* sumGenerator;
};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_HALFADDER_H