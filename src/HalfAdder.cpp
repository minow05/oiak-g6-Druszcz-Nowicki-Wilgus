#include "../include/HalfAdder.h"

void HalfAdder::execute() {
    Bit sum = x ^ y;
    Bit carry = x & y;
    for (auto fco : fcos){
        if (fco->column == column) {
            fco->setHigh(carry, sum);
        } else {
            fco->setLow(carry, sum);
        }
    }
    sumGenerator->setHalfSum(sum);
}

HalfAdder::HalfAdder
(Bit x, Bit y,
 int column,
 std::vector<FundamentalCarryOperator *> fcos,
 SumGenerator *sumGenerator) :
 x(x), y(y), column(column),
 fcos(std::move(fcos)),
 sumGenerator(sumGenerator) {}
