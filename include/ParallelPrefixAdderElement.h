#ifndef OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_PARALLELPREFIXADDERELEMENT_H
#define OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_PARALLELPREFIXADDERELEMENT_H

#include "Bit.h"

class ParallelPrefixAdderElement {
public:
    int id;
    ParallelPrefixAdderElement(int id){
        this->id = id;
    }
    void setBits(Bit high, Bit low){
        this->high = high;
        this->low = low;
    }
private:
    Bit high;
    Bit low;
};

#endif //OIAK_G6_DRUSZCZ_NOWICKI_WILGUS_PARALLELPREFIXADDERELEMENT_H
