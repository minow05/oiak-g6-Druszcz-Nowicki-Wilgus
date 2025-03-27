#include "../include/FundamentalCarryOperator.h"

FundamentalCarryOperator::FundamentalCarryOperator
(int column, std::vector<FundamentalCarryOperator*> bottomFundamentalCarryOperators) :
column(column),
bottomFundamentalCarryOperators(std::move(bottomFundamentalCarryOperators)){}

FundamentalCarryOperator::FundamentalCarryOperator
(int column,
 std::vector<Bit*> outputs) :
 column(column),
 outputs(std::move(outputs)){}

void FundamentalCarryOperator::execute() {
    Bit outGeneration = (generationLow & propagationHigh) | generationHigh;
    Bit outPropagation = propagationHigh & propagationLow;
    for (auto fco : bottomFundamentalCarryOperators) {
        if (column == fco->column) {
            fco->setHigh(outGeneration, outPropagation);
        } else {
            fco->setLow(outGeneration, outPropagation);
        }
    }
}
void FundamentalCarryOperator::setHigh(Bit generationHigh, Bit propagationHigh) {
    this->generationHigh = generationHigh;
    this->propagationHigh = propagationHigh;
}
void FundamentalCarryOperator::setLow(Bit generationLow, Bit propagationLow) {
    this->generationLow = generationLow;
    this->propagationLow = propagationLow;
}


