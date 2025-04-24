#include <iostream>
#include "../include/FundamentalCarryOperator.h"

FundamentalCarryOperator::FundamentalCarryOperator
(int column, std::vector<FundamentalCarryOperator*> bottomFundamentalCarryOperators) :
column(column),
bottomFundamentalCarryOperators(std::move(bottomFundamentalCarryOperators)){}

FundamentalCarryOperator::FundamentalCarryOperator(int column, SumGenerator *sumGenerator) :
column(column),
outSumGenerator(sumGenerator)
{}

void FundamentalCarryOperator::execute() {
    Bit outGeneration = (generationLow & propagationHigh) | generationHigh;
    Bit outPropagation = propagationHigh & propagationLow;
//    std::cout << generationLow.get() << " " << propagationLow.get() << "\n";
//    std::cout << generationHigh.get() << " " << propagationHigh.get() << "\n";
//    std::cout << outGeneration.get() << "\n" << outPropagation.get() << "\n";
    for (auto fco : bottomFundamentalCarryOperators) {
        if (column == fco->column) {
            fco->setHigh(outGeneration, outPropagation);
        } else {
            fco->setLow(outGeneration, outPropagation);
        }
    }
    outSumGenerator->setGeneration(outGeneration);
    outSumGenerator->setPropagation(outPropagation);
}
void FundamentalCarryOperator::setHigh(Bit generationHigh, Bit propagationHigh) {
    this->generationHigh = generationHigh;
    this->propagationHigh = propagationHigh;
}
void FundamentalCarryOperator::setLow(Bit generationLow, Bit propagationLow) {
    this->generationLow = generationLow;
    this->propagationLow = propagationLow;
}

FundamentalCarryOperator::FundamentalCarryOperator
(int column,
 std::vector<FundamentalCarryOperator *> bottomFundamentalCarryOperators,
 SumGenerator *sumGenerator) :
 column(column),
 bottomFundamentalCarryOperators(std::move(bottomFundamentalCarryOperators)),
 outSumGenerator(sumGenerator){}




