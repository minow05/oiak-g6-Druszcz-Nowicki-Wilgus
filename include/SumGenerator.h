#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_SUMGENERATOR_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_SUMGENERATOR_H

#include "Bit.h"

class SumGenerator {
public:
    SumGenerator(int column);
    void execute();
    void setHalfSum(Bit halfSum);
    void setCarry(Bit carry);
    void setGeneration(Bit generation);
    void setPropagation(Bit propagation);
    int column;
private:
    Bit carry, halfSum, generation, propagation;
    Bit sum;
};
#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_SUMGENERATOR_H
