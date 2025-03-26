#include "../include/FundamentalCarryOperator.h"

FundamentalCarryOperator::FundamentalCarryOperator(int id, std::vector<ParallelPrefixAdderElement*> outputs, ParallelPrefixAdderElement* highOutput) :
        ParallelPrefixAdderElement(id),
        lowOutputs(std::move(outputs)),
        highOutput(highOutput),
        generationLow(0),
        propagationLow(0),
        generationHigh(0),
        propagationHigh(0)
    {}

void FundamentalCarryOperator::setHigh(Bit generationHigh, Bit propagationHigh) {
    this->generationHigh = generationHigh;
    this->propagationHigh = propagationHigh;
}

void FundamentalCarryOperator::setLow(Bit generationLow, Bit propagationLow) {
    this->generationLow = generationLow;
    this->propagationLow = propagationLow;
}

void FundamentalCarryOperator::execute() {
    Bit outGeneration = (generationLow & propagationHigh)|generationHigh;
    Bit outPropagation = propagationLow & propagationHigh;
    for (auto output : lowOutputs){
        output->setLow(outGeneration, outPropagation);
    }
    highOutput->setHigh(outGeneration, outPropagation);
}