#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FUNDAMENTALCARRYOPERATOR_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FUNDAMENTALCARRYOPERATOR_H

#include <vector>
#include "Bit.h"
#include "ParallelPrefixAdderElement.h"

class FundamentalCarryOperator : public ParallelPrefixAdderElement {
public:
    FundamentalCarryOperator(int id, std::vector<ParallelPrefixAdderElement *> outputs,
                             ParallelPrefixAdderElement *highOutput);
    ~FundamentalCarryOperator();
    void execute();
    void setHigh(Bit generationHigh, Bit propagationHighnrt);
    void setLow(Bit generationLow, Bit propagationLow);
private:
    std::vector<ParallelPrefixAdderElement*> lowOutputs;
    ParallelPrefixAdderElement* highOutput;
    Bit generationHigh, propagationHigh, generationLow, propagationLow;

};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_FUNDAMENTALCARRYOPERATOR_H