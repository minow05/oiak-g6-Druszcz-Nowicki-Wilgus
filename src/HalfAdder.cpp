#include <utility>

#include "../include/HalfAdder.h"

void HalfAdder::execute() {
    Bit sum = x ^ y; // propagation/halfsum
    Bit carry = x & y; // generation
    bool sameColumn = false;
    for (auto fco : fcos){
        if (fco->column == column) {
            fco->setHigh(carry, sum);
            sameColumn = true;
        } else {
            fco->setLow(carry, sum);
        }
    }
    if (!sameColumn && sumGeneratorGenerationPropagation != nullptr) {
        sumGeneratorGenerationPropagation->setGeneration(carry);
        sumGeneratorGenerationPropagation->setPropagation(sum);
    }
    sumGeneratorHalfSum->setHalfSum(sum);
}

HalfAdder::HalfAdder
(Bit x, Bit y,
 int column,
 std::vector<FundamentalCarryOperator*> fcos,
 SumGenerator *sumGenerator) :
 x(x), y(y), column(column),
 fcos(std::move(fcos)),
 sumGeneratorHalfSum(sumGenerator) {}

void HalfAdder::assignGenerationPropagationSumGenerator(SumGenerator *sumGenerator) {
    this->sumGeneratorGenerationPropagation = sumGenerator;
}
