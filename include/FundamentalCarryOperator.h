#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FUNDAMENTALCARRYOPERATOR_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FUNDAMENTALCARRYOPERATOR_H

#include <vector>
#include "Bit.h"
#include "SumGenerator.h"

class FundamentalCarryOperator{
public:
    FundamentalCarryOperator(int column, std::vector<FundamentalCarryOperator*> bottomFundamentalCarryOperators);
    FundamentalCarryOperator(int column, SumGenerator*sumGenerator);
    FundamentalCarryOperator(int column, std::vector<FundamentalCarryOperator*> bottomFundamentalCarryOperators, SumGenerator* sumGenerator);
    void execute();
    void setHigh(Bit generationHigh, Bit propagationHigh);
    void setLow(Bit generationLow, Bit propagationLow);
    int column;
private:
    Bit generationHigh, propagationHigh, generationLow, propagationLow;
    std::vector<FundamentalCarryOperator*> bottomFundamentalCarryOperators;
    SumGenerator* outSumGenerator;
};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FUNDAMENTALCARRYOPERATOR_H