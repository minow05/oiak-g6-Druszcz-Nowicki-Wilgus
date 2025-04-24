#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_HALFADDER_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_HALFADDER_H

#include "FundamentalCarryOperator.h"

class HalfAdder {
public:
    HalfAdder(Bit x, Bit y, int column, std::vector<FundamentalCarryOperator*> fcos, SumGenerator* sumGenerator);
    void execute();
    int column;
    void assignGenerationPropagationSumGenerator (SumGenerator* sumGenerator);
private:
    Bit x, y;
    std::vector<FundamentalCarryOperator*> fcos;
    SumGenerator* sumGeneratorGenerationPropagation;
    SumGenerator* sumGeneratorHalfSum;

};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_HALFADDER_H